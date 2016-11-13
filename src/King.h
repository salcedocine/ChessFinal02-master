// This class is the king. It inherites from the Piece class

#ifndef KING
#define KING

#include "Piece.h"
#include "Coordinate.h"
using namespace std;
class King : public Piece
{

public:
    King (const PieceColor & C);		//Creates a king of type color
    ~King();
    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;			//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os);
};


#endif

