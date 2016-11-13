
// This class is the rook. It inherites from the Piece class

#ifndef ROOK
#define ROOK

#include "Piece.h"

class Rook : public Piece
{

public:
    Rook (const PieceColor & C);		//Creates a Rook of type color
    ~Rook();
    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;			//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os);//used to test the rook's moves
};


#endif
