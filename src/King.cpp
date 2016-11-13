#include"King.h"
#include"ChessGame.h"
#define ADD(X, Y)	if(X >=0 && Y>=0 && X<BOARD_SIZE && Y <BOARD_SIZE && (GameBoard.GetColor(Coordinate(X,Y)) !=GetColor())) ReturnSet.insert(Coordinate(X,Y));




King::King(const PieceColor & c):Piece(c,_KING)
{}
King::~King()
{}

set<Coordinate> King::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;

    //Start in the top right square and we will find squares he can move to
    //By circling around clockwise
    int X = Position.GetX()-1;
    int Y = Position.GetY()+1;

    //Add on the right side
    for (int count = 0; count<2 ; count++)
    {
        ADD(X,Y);
        X++;
    }
    //Now we are in the lower right corner

    for (int count = 0;count <2;count++)
    {
        ADD(X,Y);
        Y--;
    }

    //Now we are in the lower left corner

    for (int count = 0;count <2;count++)
    {
        ADD(X,Y);
        X--;
    }

    //Now we are in the upp left cornder

    for (int count = 0;count <2;count++)
    {

        ADD(X,Y);
        Y++;
    }

    return ReturnSet ;
}


/*!
    \fn King::Test(ostream * os)
 */
bool King::Test(ostream & os)
{

    bool success = true;
    os<<"	Testing the King"<<endl;

    set<Coordinate> Moves;
    ChessGame Game;

    Moves = Game.GetValidMoves(Coordinate(7,4));
    TEST(Moves.size() == 0 );
    Game.Move(Coordinate(7,4), Coordinate(2,4));
//used to toggle the move
    Game.Move(Coordinate(1,0), Coordinate(2,0));

    Moves = Game.GetValidMoves(Coordinate(2,4));

    TEST(Moves.size() == 3);
    CONTAINS(3,3);
    CONTAINS(3,4);
    CONTAINS(3,5);
//Now to check if the king is not surround by pieces
    Game.NewGame();
    Game.Move(Coordinate(7,4),Coordinate(4,4));
//To toggle the player
    Game.Move(Coordinate(1,0), Coordinate(2,0));

    Moves = Game.GetValidMoves(Coordinate(4,4));

    TEST(Moves.size() == 8);
    CONTAINS(5,3);
    CONTAINS(5,4);
    CONTAINS(5,5);
    CONTAINS(4,5);
    CONTAINS(3,5);
    CONTAINS(3,4);
    CONTAINS(3,3);
    CONTAINS(4,3);


    if (success)
        os<<"		Passed!"<<endl;
    return success;
}

