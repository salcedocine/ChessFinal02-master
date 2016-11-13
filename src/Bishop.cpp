#include"Bishop.h"
#include "ChessGame.h"



Bishop::Bishop(const PieceColor & c):Piece(c,_BISHOP)
{}
Bishop::~Bishop()
{}

set<Coordinate> Bishop::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;

//Set up the up right diagonal
    for (int Count = 1; Position.GetX() - Count >=0 && Position.GetY() + Count < BOARD_SIZE; Count++)
    {
        PieceColor C =GameBoard.GetColor(Coordinate(Position.GetX() - Count, Position.GetY() +Count));
        if (C != GetColor()) ReturnSet.insert(Coordinate(Position.GetX() - Count, Position.GetY() +Count));
        STOPLOOKING(C);
    }
//Set up the up left diagonal
    for (int Count =1 ; Position.GetX() - Count >=0 && Position.GetY() - Count >= 0; Count++)
    {

        PieceColor C =GameBoard.GetColor(Coordinate(Position.GetX() - Count, Position.GetY() -Count));

        if (C != GetColor())
            ReturnSet.insert(Coordinate(Position.GetX() - Count, Position.GetY() -Count));


        STOPLOOKING(C);

    }

//Set up the down right diagonal
    for (int Count =1 ; Position.GetX() + Count < BOARD_SIZE && Position.GetY() + Count < BOARD_SIZE; Count++)
    {

        PieceColor C =GameBoard.GetColor(Coordinate(Position.GetX() + Count, Position.GetY() +Count));

        if (C != GetColor())
            ReturnSet.insert(Coordinate(Position.GetX() + Count, Position.GetY() +Count));


        STOPLOOKING(C);

    }
//Set up the down left diagonal
    for (int Count =1 ; Position.GetX() + Count < BOARD_SIZE && Position.GetY() - Count >= 0; Count++)
    {

        PieceColor C =GameBoard.GetColor(Coordinate(Position.GetX() + Count, Position.GetY() -Count));

        if (C != GetColor())
            ReturnSet.insert(Coordinate(Position.GetX() + Count, Position.GetY() -Count));


        STOPLOOKING(C);

    }

    return ReturnSet ;
}



bool Bishop::Test(ostream & os)
{
    bool success = true;
    os<<"	Testing the Bishop"<<endl;

    set<Coordinate> Moves;
    ChessGame Game;

//Test the start location
    Moves = Game.GetValidMoves(Coordinate(7,2));
    TEST(Moves.size() == 0);
//Move the bishop to the center of the board
    Game.Move(Coordinate(7,2), Coordinate(4,4));
//used to toggle the player back
    Game.Move(Coordinate(1,0), Coordinate(1,1));
    Moves = Game.GetValidMoves(Coordinate(4,4));


    TEST(Moves.size() == 8);
//which should only contain the following 8 squares
    CONTAINS(5,5);
    CONTAINS(5,3);
    CONTAINS(3,3);
    CONTAINS(2,2);
    CONTAINS(1,1);
    CONTAINS(3,5);
    CONTAINS(2,6);
    CONTAINS(1,7);


    if (success)
        os<<"		Passed!"<<endl;
    return success;
}
