#include"Rook.h"
#include "ChessGame.h"

Rook::Rook(const PieceColor & c):Piece(c,_ROOK)
{}
Rook::~Rook()
{}

set<Coordinate> Rook::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;


    //First get all of the squares a head
    for (int Count = Position.GetX()-1; Count>= 0; Count--)
    {
        PieceColor C =GameBoard.GetColor(Coordinate(Count, Position.GetY()));

        if ( C!= GetColor())
            ReturnSet.insert(Coordinate(Count,Position.GetY()));
        STOPLOOKING(C);


    }
    //All the squares behind
    for (int Count = Position.GetX()+1; Count< BOARD_SIZE ; Count++)
    {
        PieceColor C =GameBoard.GetColor(Coordinate(Count, Position.GetY()));

        if ( C!= GetColor())
            ReturnSet.insert(Coordinate(Count,Position.GetY()));

        STOPLOOKING(C);

    }
    //and to the left
    for (int Count = Position.GetY()-1; Count>= 0; Count--)
    {

        PieceColor C = GameBoard.GetColor(Coordinate(Position.GetX(),Count));

        if ( C != GetColor())
            ReturnSet.insert(Coordinate(Position.GetX(),Count));

        STOPLOOKING(C);
    }
    for (int Count = Position.GetY()+1; Count< BOARD_SIZE; Count++)
    {

        PieceColor C = GameBoard.GetColor(Coordinate(Position.GetX(),Count));

        if ( C != GetColor())
            ReturnSet.insert(Coordinate(Position.GetX(),Count));

        STOPLOOKING(C);
    }


    return ReturnSet ;
}

bool Rook::Test(ostream & os)
{
    bool success = true;
    os<<"	Testing the Rook"<<endl;

    set<Coordinate> Moves;
    ChessGame Game;


//Get the valid moves for the rook in the corner
    Moves = Game.GetValidMoves(Coordinate(7,0));
//should have any valid moves
    TEST(Moves.size() ==0);

//Moving the rook into the center
    Game.Move(Coordinate(7,0), Coordinate(4,4));
//Just to toogle the turn
    Game.Move(Coordinate(1,0), Coordinate(2,0));

    Moves = Game.GetValidMoves(Coordinate(4,4));
//should have 11 places to move to
    TEST(Moves.size()== 11);
//should be 4 before the piece
    for (int count = 0 ;count < 4; count++)
        CONTAINS(4,count);
//should be 3 after
    for (int count = 5; count < 8; count++)
        CONTAINS(4,count);
//one underneath
    CONTAINS(5,4);

//should be 3 above
    for (int count =1; count < 4; count++)
        CONTAINS(count,4);
//and that makes 11!


    if (success)
        os<<"		Passed!"<<endl;
    return success;



}
