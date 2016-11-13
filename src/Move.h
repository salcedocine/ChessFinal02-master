//This class is used to store all of the information


#ifndef MOVE
#define MOVE

#include"Coordinate.h"
#include"Piece.h"
#include<string>



class Move
{

public:
//   Move(const PieceType & PieceMoved, const Coordinate & From, const Coordinate & To);	//A piece moved from a to b
    Move(const PieceType & PieceMoved,const PieceColor & ColorOfMoved, const Coordinate & From, const Coordinate & To,bool FirstMove, Piece * KilledPiece); //A piece moved from a to b and kill someone
    Move(const Move & Other);		//Copy constructor
    Move & operator = (const Move & Other);		//Assignment

    ~Move(); //Destructor. Specifically for delete the killed piece type if there is one

    //Getters for the move
    PieceType GetPieceMoved()const
    {
        return PieceMoved;
    }
    Coordinate GetOriginalLoc()const
    {
        return From;
    }
    Coordinate GetDestinationLoc()const
    {
        return To;
    }
    bool IsFirstMove()const
    {
        return FirstMove;
    }
    Piece * GetKilled() const
    {
        return Killed;
    }
    std::string ToXml();	//Returns a string representation in xml
    PieceColor ColorMoved() const
    {
        return ColorOfMoved;
    }


private:
    PieceType PieceMoved;			//Used to store the piece moved
    PieceColor ColorOfMoved;
    Coordinate From;			//Used to store where the piece came from
    Coordinate To; 				//Used to store where the piece went


    void Copy(const Move & Other);
    bool FirstMove;
    Piece * Killed;



};








#endif

