#include"Board.h"

#include<iostream>
#include<string>
#include"Utils.h"

Board::Board()
{
    NewGame();

}
void Board::Clear()
{
//iteration through the board and removes each piece
    for (int X = 0; X<BOARD_SIZE; X++)
        for (int Y = 0; Y< BOARD_SIZE; Y++)
            Squares[X][Y].RemovePiece();



}

void Board::NewGame()
{
    Clear();

    //First place pawns. on 1,x and 6,x
    for (int count = 0; count< BOARD_SIZE; count++)
    {


        Squares[1][count].CreatePiece(_PAWN,_BLACK);
        Squares[6][count].CreatePiece(_PAWN, _WHITE);
    }


    //Place bishops
    Squares[0][2].CreatePiece(_BISHOP,_BLACK);
    Squares[0][5].CreatePiece(_BISHOP,_BLACK);
    Squares[7][2].CreatePiece(_BISHOP,_WHITE);
    Squares[7][5].CreatePiece(_BISHOP,_WHITE);

    //Place rooks
    Squares[0][0].CreatePiece(_ROOK,_BLACK);
    Squares[0][7].CreatePiece(_ROOK,_BLACK);
    Squares[7][0].CreatePiece(_ROOK,_WHITE);
    Squares[7][7].CreatePiece(_ROOK,_WHITE);

    //Place knights
    Squares[0][1].CreatePiece(_KNIGHT,_BLACK);
    Squares[0][6].CreatePiece(_KNIGHT,_BLACK);
    Squares[7][1].CreatePiece(_KNIGHT,_WHITE);
    Squares[7][6].CreatePiece(_KNIGHT,_WHITE);

    //place queens
    Squares[0][3].CreatePiece(_QUEEN,_BLACK);
    Squares[7][3].CreatePiece(_QUEEN,_WHITE);

    //place kings
    Squares[0][4].CreatePiece(_KING,_BLACK);
    Squares[7][4].CreatePiece(_KING,_WHITE);


    CalculateAllMoves();
}


Square * Board::GetSquare(const Coordinate & Coord)
{
    return &Squares[Coord.GetX()][Coord.GetY()]; //round about way to cast
}


const Square * Board::GetSquare(const Coordinate & Coord) const
{
    return &Squares[Coord.GetX()][Coord.GetY()]; //round about way to cast a const * to a normal one
}


PieceColor Board::GetColor(const Coordinate & Location) const
{
    PieceColor ReturnValue;

    if (Squares[Location.GetX()][Location.GetY()].GetPiece() != NULL)			//Return the color of the piece if it's not null else return no color
        ReturnValue = Squares[Location.GetX()][Location.GetY()].GetPiece()->GetColor();
    else
        ReturnValue = _NOCOLOR;

    return ReturnValue;

}


void Board::CalculateAllMoves()
{
    AllWhiteMoves.clear();
    AllBlackMoves.clear();

    for (int X = 0; X< BOARD_SIZE; X++)	//Iterate through each square
        for (int Y = 0; Y < BOARD_SIZE; Y++)
        {


            const Piece * PP = (GetSquare(Coordinate(X,Y))) -> GetPiece();
            if (PP==NULL)	//if that piece is null, skip it
                continue;
            PieceColor C = PP->GetColor();	//First get the color of that piece
            set<Coordinate> CanaditeSet = PP->GetValidMoves(*this,Coordinate(X,Y)); //this set is used to take all of the moves from the piece
            set<Coordinate>::iterator PI = CanaditeSet.begin();//so we have an iterator

            while (PI != CanaditeSet.end())
            {
                if (C == _BLACK)	//if the c color is black, add it to black's moves
                    AllBlackMoves.insert(*PI);
                if (C == _WHITE)	//else add it to whites'
                    AllWhiteMoves.insert(*PI);
                PI++;
            }


        }


}
Coordinate Board::FindKing(const PieceColor & C) const
{
    Coordinate ReturnValue;

    for (int X = 0; X<BOARD_SIZE; X++)	//just iteratre through the board and look for the king. In theory it should find it since the king
        for (int Y = 0; Y<BOARD_SIZE; Y++)
        {
            ReturnValue = Coordinate(X,Y);

            Piece * P = Squares[X][Y].GetPiece();
            if (P==NULL)
                continue;
            if (P->GetType() ==_KING && P->GetColor() ==C)
                return ReturnValue;
        }



    return ReturnValue;
}

void Board::WriteXml(std::ofstream & Output) const
{

    Output<<"\t<board>"<<endl;

    for (int X = 0; X < BOARD_SIZE; X++)
        for (int Y = 0; Y < BOARD_SIZE; Y++)
        {
            if (Squares[X][Y].GetPiece() !=NULL)
            {
                string Type = PieceTypeToString(Squares[X][Y].GetPiece()->GetType());

                string Color = ColorToString(Squares[X][Y].GetPiece()->GetColor());



                Output<<"\t\t<piece type = \""<<Type<<"\" row = \""<<X<< "\" column = \""<<Y<<"\"";
                Output<<" color = \""<<Color<<"\""<< "/>"<<endl;


            }


        }

    Output<<"\t</board>"<<endl;

}
