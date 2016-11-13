//This class is the mastermind of the chess game. It contains the board (which contains the pieces), the move history, and provides an interface for playing chess;





#ifndef CHESSGAME

#define CHESSGAME
#include"Move.h"
#include"Board.h"
#include"Coordinate.h"
#include"Piece.h"
#include<set>
#include<fstream>
#include<map>
#include<stack>
#include<Move.h>
#include<deque>

class ChessGame
{
public:
    ChessGame();		//This constructor initializes a new game
    ~ChessGame();
    bool InCheck() const;		//Returns true if the current player is in check
    bool InCheckMate();	//Returns true if the current player is in checkmate
    bool InStaleMate();	//Returns true if the current player is in stalemate
    set<Coordinate>GetValidMoves(const Coordinate & C);	//Returns a set of valid coordnates for the given location
    void Move(const Coordinate & From, const Coordinate & To);		//Move a piece from a location to a given one
    void NewGame();	 //Sets the board up and clears the history;
    void UndoLastMove();		//Undos the last move from the board and history
    void Save(const string & FileName);	//Saves the game to the given file name
    void Load(const string & FileName); //Loads a game from the given file name
    Piece * GetPiece(const Coordinate & C)  ;	//Returns a pointer to the peice at the given coordnates
    PieceColor GetTurn() const;		//returns the current players color





private:


    PieceColor PlayerTurn;  		//Used to store which players move it is
    deque<class Move> History;			//Used to store the history of moves
    Board 	GameBoard;			//The main board;
    bool MakesCheck(const Coordinate & From, const Coordinate & To);	//Used to check if a move creates check or not;
    set<Coordinate>GetAllValidMoves(const PieceColor & Color);	//Find all of the valid moves of the given color
    void WriteHistoryXml(std::ofstream & Output);	//Writes the history to the given output in Xml
    Coordinate ReadLocation(std::ifstream &);	//Takes the line and reads the row and columns into the coordinate
    void ClearHistory();


};






#endif

