#include "Queen.h"
#include "ChessGame.h"
#include <algorithm>


Queen::Queen(const PieceColor & c):Piece(c,_QUEEN)
{}
Queen::~Queen()
{}

#include<iostream>
using namespace std;
set<Coordinate> Queen::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;

    //will combine the moves from a rook and a bishop and union them together
    Rook TempRook(GetColor());
    Bishop TempBishop(GetColor());

    set<Coordinate> RookSet (TempRook.GetValidMoves(GameBoard,Position));
    set<Coordinate> BishopSet (TempBishop.GetValidMoves(GameBoard,Position));

    set<Coordinate>::iterator it = RookSet.begin();


    while (it != RookSet.end())
    {
        ReturnSet.insert( *it);
        it++;
    }

    it = BishopSet.begin();
    while (it != BishopSet.end())
    {
        ReturnSet.insert( *it);
        it++;
    }










    return ReturnSet ;
}




bool Queen::Test(ostream & os)
{
    bool success = true;
    os<<"	Testing the Queen"<<endl;

    set<Coordinate> Moves;
    ChessGame Game;

//Test the start location
    Moves = Game.GetValidMoves(Coordinate(7,3));
    TEST(Moves.size() == 0);
//Move the queen to the center of the board
    Game.Move(Coordinate(7,3), Coordinate(4,4));
//used to toggle the player back
    Game.Move(Coordinate(1,0), Coordinate(1,1));
    Moves = Game.GetValidMoves(Coordinate(4,4));

    TEST(Moves.size() == 19);
//which should only contain the following 8 squares
    CONTAINS(5,5);
    CONTAINS(5,3);
    CONTAINS(3,3);
    CONTAINS(2,2);
    CONTAINS(1,1);
    CONTAINS(3,5);
    CONTAINS(2,6);
    CONTAINS(1,7);


//should be 4 before the piece
    for (int count = 0 ;count < 4; count++)
        CONTAINS(4,count);
//should be 3 after
    for (int count = 5; count < 8; count++)
        CONTAINS(4,count);
//one underneath
    CONTAINS(5,4);
//3 above
    for (int count =1; count < 4; count++)
        CONTAINS(count,4);

//makes all 19 squares tested

    if (success)
        os<<"		Passed!"<<endl;
    return success;
}



