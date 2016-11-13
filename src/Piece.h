//This is the parent class of all of the peices on the board. This will contain virtual methods and data that each peice needs.





#ifndef PIECECLASS
#define PIECECLASS
#define STOPLOOKING(X) if( X!=_NOCOLOR) break
enum PieceColor {_BLACK,_WHITE, _NOCOLOR};
enum PieceType {_BISHOP, _PAWN, _KNIGHT,_QUEEN, _ROOK, _KING, 
	_BLANK_PIECE};

class Board;	//Forward declariont of board
class Piece;	//Forward delcartion needed for the board header file
#include"Board.h"
#include<set>
#include"Coordinate.h"
#include<string>


using namespace std;





class Piece
{
public:
    Piece(const PieceColor & C, const PieceType & T) ;	//When a Piece is created, it needs to know  it's color and it's type

    virtual set<Coordinate> GetValidMoves (const Board & GameBoard, const Coordinate & Position) const;	//Returns a set of all the valid moves for a peice
    virtual ~Piece();	//Deconstructor
    Piece(Piece & Other) ;


    PieceType GetType() const ;//Returns the type the peice is
    PieceColor GetColor() const ;	//Returns the color of the peice
    bool HasMoved()const
    {
        return Moved;    //REturns if the pieces has been moved
    }
    void MadeMove()
    {
        Moved = true;    //Sets that piece as moved
    }
    void SetMoved(bool M)
    {
        Moved = M;
    }



private:
    PieceColor Color;		//Each piece has a color
    void Copy(Piece & orther);			//Copies one pieces data to this one
    PieceType Type;			//Each piece has a type
    bool Moved;





};

//When you include the piece class you might as well get all of the pieces
#include"Knight.h"
#include"King.h"
#include"Queen.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Rook.h"


#endif







