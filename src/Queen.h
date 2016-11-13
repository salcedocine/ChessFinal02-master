
// This class is the queen. It inherites from the Piece class

#ifndef QUEEN
#define QUEEN

#include "Piece.h"
#include "Bishop.h"

class Queen : public Piece
{

public:
    Queen (const PieceColor & C);		//Creates a Queen of type color
    ~Queen();
    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;			//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os);
};


#endif
