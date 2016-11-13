
//Class that contains the squares. Each square contains the piece that resides on it



#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include"Square.h"
#include"Coordinate.h"
#include <set>
#include <string>
#include<fstream>
using namespace std;

class Board
{
public:
    Board();		//no arg constructor. Will Place ceach piece in appropriate places
    Square * GetSquare(const Coordinate & Location)  ;	//Returns a pointer to a square at the given location
    const Square * GetSquare(const Coordinate & Location)const  ;	//Returns a pointer to a square at the given location
    void NewGame();		//Reititalizes the board
    PieceColor GetColor(const Coordinate & Locations) const;	//Returns the color on that square
    void CalculateAllMoves() ;	//used to calculate all of the moves
    set<Coordinate> GetWhiteMoves() const//Returns all of the calculated moves for white
    {
        return AllWhiteMoves;
    }
    set<Coordinate> GetBlackMoves() const //Returns all of the calculate moves for black
    {
        return AllBlackMoves;
    }
    Coordinate FindKing(const PieceColor & C) const;	//Returns a pointer to the king of the given color
    void WriteXml(std::ofstream & output) const;		//Returns an xml representation of the board

    std::size_t width() const
    {
        return BOARD_SIZE;
    }

    std::size_t height() const
    {
        return BOARD_SIZE;
    }

    
private:
    Square Squares[BOARD_SIZE][BOARD_SIZE] ;	//Used store the peices and their locations

    set<Coordinate> AllBlackMoves;	//Used to store all the moves for black
    set<Coordinate>AllWhiteMoves; //used to store all the moves for white
    void Clear();		//Clears the board of all the pieces
};






#endif
