// This class is the bishop. It inherites from the Piece class

#ifndef BISHOP
#define BISHOP

#include "Piece.h"
#include"Coordinate.h"
#include"Board.h"


class Bishop : public Piece
{

public:
    Bishop (const PieceColor & C);		//Creates a bishop of type color

    ~Bishop();			//Deconstructor
    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;		//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os);	//test code for the bishop

};

#endif
