// This class is the pawn. It inherites from the Piece class

#ifndef PAWN
#define PAWN

#include "Piece.h"
#include <set>
#include <iostream>

#include "UnitTest.h"

class Pawn: public Piece
{

public:
    Pawn (const PieceColor & C);		//Creates a pawn of type color
    ~Pawn();				//Deconstructor

    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;			//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os); //test driver
};


#endif
