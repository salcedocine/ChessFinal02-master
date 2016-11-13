#include"Pawn.h"
#include "UnitTest.h"
#include "ChessGame.h"
#include <fstream>


Pawn::Pawn(const PieceColor & c):Piece(c,_PAWN)
{

}

Pawn::~Pawn()
{}

set<Coordinate> Pawn::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;

    int Forward = -1;
    if ( GetColor () == _BLACK)
        Forward *= -1;
	
     if(Position.GetX() +Forward <0 || Position.GetX() +Forward >= BOARD_SIZE)
	     return ReturnSet;
	

    if (GameBoard.GetColor(Coordinate(Position.GetX()+Forward,Position.GetY() )) == _NOCOLOR)
    {
        ReturnSet.insert(Coordinate(Position.GetX() +Forward, Position.GetY()));
        //Can go forward if it hasn't moved
        if (!HasMoved())
            if (GameBoard.GetColor(Coordinate(Position.GetX()+2*Forward,Position.GetY() )) == 	_NOCOLOR)
                ReturnSet.insert(Coordinate(Position.GetX() +2*Forward, Position.GetY()));
    }

    //Check diagonals

    if (Position.GetY() >0)
        if (GameBoard.GetColor(Coordinate(Position.GetX() +Forward, Position.GetY()-1)) != GetColor() &&
                GameBoard.GetColor(Coordinate(Position.GetX() +Forward, Position.GetY()-1 )) !=_NOCOLOR)
            ReturnSet.insert(Coordinate(Position.GetX() +Forward, Position.GetY()-1));
    if (Position.GetY() < BOARD_SIZE -1 )
        if (GameBoard.GetColor(Coordinate(Position.GetX() +Forward, Position.GetY()+1)) != GetColor() &&
                GameBoard.GetColor(Coordinate(Position.GetX() +Forward, Position.GetY()+1 )) !=_NOCOLOR)
            ReturnSet.insert(Coordinate(Position.GetX() +Forward, Position.GetY()+1));


    return ReturnSet;
}



bool Pawn::Test(ostream & os)
{
    bool success = true;
// First I will create a chess game
    os<<"	Testing the Pawn"<<endl;
    ChessGame Game;

    set<Coordinate> Moves;	//used to store the potential moves

//Grabe the coordinates from a pawn peice
    Moves = Game.GetValidMoves(Coordinate(6,0));

//should contain only 2 possible places
    TEST(Moves.size()==2);

//should only contain 5,0 and 4,0 for the first move
// TEST(Moves.find(Coordinate(5,0)) != Moves.end());
    TEST(Moves.find(Coordinate(4,0)) != Moves.end());

//now need to check that it attacks diagonally

    Game.Move(Coordinate(1,4),Coordinate(5,4));
    Moves = Game.GetValidMoves(Coordinate(5,4));

    CONTAINS(6,3);
    CONTAINS(6,5);
//now need to check that it only contains 1 square if it has moved
    Game.Move(Coordinate(6,6),Coordinate(5,6));
    Moves = Game.GetValidMoves(Coordinate(5,6));
    TEST(Moves.size() ==1);
    CONTAINS(4,6);
    if (success)
        os<<"		Passed!"<<endl;

    return success;
}




