//The square class which will contain a pointer  to a chess peice.



#ifndef SQUARE
#define SQUARE
#include "Piece.h"
#include<string>

using namespace std;

class Square
{
public:
    Square ();	//No arg constructor. Will just contain a null pointer to a piece
    void CreatePiece(PieceType  NewPiece, PieceColor Color);	// Creates a new piece for the square to point at

    ~Square();		//Will delete the piece it's pointing to if it's not null
    Piece *  GetPiece()const;	//Will return a pointer the piece it's pointing to;
    void SetPiece (Piece * IncomingPiece);	//Sets the piecepointer to the pointer given
    void RemovePiece ();			//Deletes the current piece on the square;
private:
    Piece * PiecePointer;	//Used to point to it's piece
    std::string ToXml();	//Returns a string representation in xml
};


#endif
