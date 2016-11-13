#include"ChessGame.h"
#define TOGGLEPLAYER	if(PlayerTurn ==_WHITE) PlayerTurn = _BLACK; else PlayerTurn = _WHITE

#include<iostream>
#include <assert.h>
#include "Move.h"
#include <fstream>
#include "FileException.h"
#include "Utils.h"
#include <cctype>
#define FOUND != string::npos
#define NOT_FOUND == string::npos



using namespace std;

ChessGame::ChessGame(): PlayerTurn(_WHITE)
{
    NewGame();
}

ChessGame::~ChessGame()
{
    //The pieces are created in the board class
    //However when a piece is kill, the pointer to it is transfered to the history set
    //and the history set does not clean them up for copying purposes
    //so i do here
    set<class Move>::iterator it;
    ClearHistory();


}

void ChessGame::NewGame()
{
    GameBoard.NewGame();
    ClearHistory();
    PlayerTurn = _WHITE;


}



Piece * ChessGame::GetPiece(const Coordinate & Coords)
{


    const Square * SquareP = GameBoard.GetSquare(Coordinate(Coords.GetX(),Coords.GetY()));
    if (SquareP !=NULL)
        return SquareP->GetPiece();
    else
        return NULL;


}


set<Coordinate> ChessGame::GetValidMoves(const Coordinate & C)
{
    set<Coordinate> ReturnSet;
    const Piece * CanaditePiece = GetPiece(C);	//The piece we are getting the valid coordinates for


    std::cout << "in here " << std::endl;

    if (CanaditePiece != NULL && (CanaditePiece->GetColor()==PlayerTurn))
    {

//        std::cout << "a. blah?? " << std::endl;

        ReturnSet= CanaditePiece->GetValidMoves(GameBoard, C);


    }
    else
    {
//        std::cout << "b. hmm?? " << std::endl;

        return ReturnSet; //return the empty set if either the piece isn't right or there is no piece there

    }
    
    
    
    
    set<Coordinate>::iterator it (ReturnSet.begin());

    while (it != ReturnSet.end())//	iteratre through the valid moves
    {

        set<Coordinate>::iterator temp;
        if (MakesCheck(C, *it))	// if the pices makes check
        {
            temp = it;
            it++;
            ReturnSet.erase(*temp);//throw it away
            continue;
        }
        it++;
    }


    return ReturnSet;
}

void ChessGame::Move(const  Coordinate & From, const Coordinate & To)
{
    Square * FirstSquare =GameBoard.GetSquare(From);	//The from sqaures
    Square * SndSquare = GameBoard.GetSquare(To);	// the to square

    Piece * Temp = FirstSquare->GetPiece();		//to temporily store the first square
    FirstSquare->SetPiece(NULL);			//and set it to null

    PieceType Killed(_BLANK_PIECE);				//used to store the type of the kill
    PieceColor ColorKilled(_NOCOLOR);			//used to store the color of the kill


    if (SndSquare->GetPiece() !=NULL)			//if there's a piece there
    {
        Killed = SndSquare->GetPiece()->GetType();	// set the killed type
        ColorKilled = SndSquare->GetPiece()->GetColor();//and the color

    }


    class Move RecentMove(Temp->GetType(), Temp->GetColor(), From, To,!Temp->HasMoved(), SndSquare->GetPiece()  );//

    SndSquare->SetPiece(Temp);	//Move the pices
    Temp->MadeMove();	//Set the piece so that it has "moved"



    History.push_back(RecentMove);//push the recent move onto the history
    TOGGLEPLAYER;
    GameBoard.CalculateAllMoves();

}

PieceColor ChessGame::GetTurn() const
{
    return PlayerTurn;

}

bool ChessGame::InCheck() const
{
    //First I will find the king for the current player
    Coordinate KingLoc(GameBoard.FindKing(GetTurn()));



    //Now I will find all of the possible moves for the opposing player
    set<Coordinate> OppMoves;
    OppMoves = (GetTurn() ==_BLACK ? GameBoard.GetWhiteMoves() : GameBoard.GetBlackMoves() );

    //If the opposing player's moves contain the player's king I will return true

    //Else I will return false
    if (OppMoves.find(KingLoc) != OppMoves.end())
        return true;
    else
        return false;


}

void ChessGame::UndoLastMove()
{
    if (History.empty())
        return;
    class Move RecentMove (History.back());

    History.pop_back();
    Move(RecentMove.GetDestinationLoc(),RecentMove.GetOriginalLoc());
    History.pop_back();//Since move added to the history..which is bad
    GameBoard.GetSquare(RecentMove.GetOriginalLoc())->GetPiece()->SetMoved(!RecentMove.IsFirstMove());
    GameBoard.GetSquare(RecentMove.GetDestinationLoc())->SetPiece(RecentMove.GetKilled());
    GameBoard.CalculateAllMoves();




}

bool ChessGame::MakesCheck(const Coordinate & From, const Coordinate & To)
{
//simulate the move and check to see if the player is in check...then undo it
    Move(From, To);
    TOGGLEPLAYER;

    if (InCheck())
    {
        TOGGLEPLAYER;
        UndoLastMove();
        return true;
    }

    TOGGLEPLAYER;
    UndoLastMove();


    return false;
}

bool ChessGame::InStaleMate()
{

    if (GetAllValidMoves(GetTurn()).empty())
        return true;
    else
        return false;
}

set<Coordinate> ChessGame::GetAllValidMoves(const PieceColor & Color)
{
    set<Coordinate> ReturnSet;
    //Iteratre through the whole board and grab all the moves of the current color
    //and make one big set
    for (int X = 0;X < BOARD_SIZE; X++)
        for (int Y = 0; Y < BOARD_SIZE; Y++)
        {
            Piece * CanaditePiece = GameBoard.GetSquare(Coordinate(X,Y))->GetPiece();
            set<Coordinate>CanaditeCoords;

            if (CanaditePiece ==NULL)
                continue;
            if (CanaditePiece->GetColor()==GetTurn())
                CanaditeCoords = CanaditePiece->GetValidMoves(GameBoard,Coordinate(X,Y));
            set<Coordinate>::iterator it(CanaditeCoords.begin());
            while (it!=CanaditeCoords.end())
            {
                if (!MakesCheck(Coordinate(X,Y),*it))
                    ReturnSet.insert(*it);
                it++;
            }



        }



    return ReturnSet;
}

bool ChessGame::InCheckMate ()
{

    return InStaleMate() && InCheck();

}

void  ChessGame::Save(const std::string & FileName)
{
    std::ofstream Output (FileName.c_str());
    if (Output.fail())
        throw FileException(FileName);//Throw an exception!

//open the chessgame
    Output<<"<chessgame>"<<endl;

//First output the Board
    GameBoard.WriteXml(Output);

//Then output each move
    WriteHistoryXml(Output);

//close the chessgame
    Output<<"</chessgame>"<<endl;

    Output.close();
}


void ChessGame::WriteHistoryXml(std::ofstream & Output)
{
    Output<<"\t<history>"<<endl;

    deque<class Move>::iterator it(History.begin());
    while (it!=History.end())
    {
        //prints the piece moved
        Output<<"\t\t<move>"<<endl;
        Output<<"\t\t\t<piece type = \""<<PieceTypeToString(it->GetPieceMoved())<<"\" ";
        Output<<" color = \""      <<ColorToString(it->ColorMoved())<<"\"";
        Output<<" row = "   <<"\""<<it->GetOriginalLoc().GetX()<<"\"";
        Output<<" column = "<<"\""<<it->GetOriginalLoc().GetY()<<"\"";
        Output<<"/>\n";
        //prints where the piece went to
        Output<<"\t\t\t<piece type = \""<<PieceTypeToString(it->GetPieceMoved())<<"\" ";
        Output<<" color = \""      <<ColorToString(it->ColorMoved())<<"\"";
        Output<<" row = "   <<"\""<<it->GetDestinationLoc().GetX()<<"\"";
        Output<<" column = "<<"\""<<it->GetDestinationLoc().GetY()<<"\"";
        Output<<"/>\n";

        //Now to print the Killed peice
        if (it->GetKilled() != NULL)
        {
            Output<<"\t\t\t<piece type = \""<<PieceTypeToString(it->GetKilled()->GetType())<<"\"";
            Output<<" color = \"" <<ColorToString(it->GetKilled()->GetColor())<<"\"";
            Output<<" row = "   <<"\""<<it->GetDestinationLoc().GetX()<<"\"";
            Output<<" column = "<<"\""<<it->GetDestinationLoc().GetY()<<"\"";
            Output<<"/>\n";
        }
        Output<<"\t\t</move>"<<endl;
        it++;
    }


    Output<<"\t</history>"<<endl;
}


void ChessGame::Load(const std::string & FileName)
{
    using namespace std;;
    ifstream Input (FileName.c_str());
    if (Input.fail())
        throw FileException(FileName);//Throw an exception!

    NewGame();
//char ReadChar;
    char Read;
    Input >>Read;




    while (!Input.eof()) //goes to history
    {
        Input>>Read;
        if (Read =='h')
        {
            Input>>Read;
            if (Read =='i')
            {
                Input>>Read;
                if (Read =='s')
                {
                    Input>>Read;
                    if (Read =='t')
                    {
                        Input>>Read;
                        if (Read =='o')
                        {
                            Input>>Read;
                            if (Read =='r')
                            {
                                Input>>Read;
                                if (Read =='y')
                                    break;
                            }
                        }
                    }

                }
            }
        }


    }

    while (!Input.eof())
    {



        if (Read =='m')
        {
            Input>>Read;
            if (Read =='o')
            {
                Input>>Read;
                if (Read=='v')
                {
                    Input>>Read;
                    if (Read =='e')
                    {
                        Coordinate From;	//used for the original location of the piece
                        Coordinate To;		//used for the destination location of the piece


                        From = ReadLocation(Input);
                        To   = ReadLocation(Input);
                        Move(From,To);

                    }
                }
            }

            while (!Input.eof())	//clear out the closing move
            {
                Input>>Read;
                if (Read=='m')
                {
                    Input>>Read;
                    if (Read=='o')
                    {
                        Input>>Read;
                        if (Read=='v')
                        {
                            Input>>Read;
                            if (Read =='e')
                                break;
                        }
                    }
                }
            }
            continue;
        }

        Input>>Read;

    }











}

Coordinate ChessGame::ReadLocation(ifstream & Input)
{
    Coordinate ReturnValue;
    char Read;




    while (!Input.eof()) //goes to Piece
    {
        Input>>Read;
        if (Read =='p')
        {
            Input>>Read;
            if (Read =='i')
            {
                Input>>Read;
                if (Read =='e')
                {
                    Input>>Read;
                    if (Read =='c')
                    {
                        Input>>Read;
                        if (Read =='e')
                            break;
                    }


                }
            }
        }
    }






    while (Read !='/' )
    {


        if (Read == 'r')
        {
            Input>>Read;
            if (Read =='o')
            {
                Input>>Read;
                if (Read =='w')
                {



                    while (!isdigit(Read=Input.get()));

                    ReturnValue.SetX(Read-48);



                }
            }
            continue;
        }

        if (Read =='c')
        {
            Input>>Read;
            if (Read=='o')
            {
                Input>>Read;
                if (Read=='l')
                {
                    Input>>Read;
                    if (Read=='u')
                    {
                        Input>>Read;
                        if (Read=='m')
                        {
                            Input>>Read;
                            if (Read=='n')
                            {



                                while (!isdigit(Read=Input.get()));

                                ReturnValue.SetY(Read-48);


                            }
                        }
                    }
                }
            }
            continue;
        }



        Input>>Read;



    }

    return ReturnValue;
}


/*!
    \fn ChessGame::ClearHistory()
 */
void ChessGame::ClearHistory()
{
    while (!History.empty())
    {
        delete History.back().GetKilled();

        History.pop_back();
    }
}
