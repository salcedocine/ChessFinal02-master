
// This class is the knight. It inherites from the Piece class

#ifndef KNIGHT
#define KNIGHT

#include "Piece.h"
#include "Coordinate.h"

class Knight : public Piece
{

public:
    Knight (const PieceColor & C);		//Creates a Knight of type color
    ~Knight();

    set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;			//Returns a set of all the valid moves for a peice
    static bool Test(ostream & os);


private:
    bool IsValidMove(const Board & GameBoard, const Coordinate & Position) const; //true if the color of position is different from  the current peice
};


#endif




