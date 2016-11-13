#include"Knight.h"
#include"ChessGame.h"
#define TRYTOADD(X,Y)	if(X>=0 && Y>=0 && X<BOARD_SIZE && Y<BOARD_SIZE) if(IsValidMove(GameBoard,Coordinate(X,Y))) ReturnSet.insert(Coordinate(X,Y))

Knight::Knight(const PieceColor & c):Piece(c,_KNIGHT)
{}
Knight::~Knight()
{}

set<Coordinate> Knight::GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;
    Coordinate CanaditeCoord;
    int X = 0;
    int Y = 0;

    //first will check right one down 2
    X = Position.GetX()+2;
    Y = Position.GetY()+1;
    TRYTOADD(X,Y);

    //now right 2 and down 1
    X = Position.GetX()+1;
    Y = Position.GetY()+2;
    TRYTOADD(X,Y);

    //right 2 up 1
    X = Position.GetX()-1;
    Y = Position.GetY()+2;
    TRYTOADD(X,Y);
    //right 1 up 2
    X = Position.GetX()-2;
    Y = Position.GetY()+1;
    TRYTOADD(X,Y);
    //left 1 up 2
    X = Position.GetX()-2;
    Y = Position.GetY()-1;
    TRYTOADD(X,Y);
    //left 2 down 1;
    X = Position.GetX()-1;
    Y = Position.GetY()-2;
    TRYTOADD(X,Y);
    //left 2 down 1;
    X = Position.GetX()+1;
    Y = Position.GetY()-2;
    TRYTOADD(X,Y);
    //left 1 down 2
    X = Position.GetX()+2;
    Y = Position.GetY()-1;
    TRYTOADD(X,Y);





    return ReturnSet ;
}
bool Knight::IsValidMove(const Board & GameBoard, const Coordinate & Position) const
{
    bool ReturnValue(true);

    if (GameBoard.GetSquare(Position)->GetPiece()!=NULL)
        if (GameBoard.GetSquare(Position)->GetPiece()->GetColor() == GetColor())
            ReturnValue = false;



    return ReturnValue;
}


/*!
    \fn Knight::Test(ofstream & os)
 */
bool Knight::Test(ostream & os)
{
    bool success = true;
    os<<"	Testing the Knight"<<endl;

    set<Coordinate> Moves;
    ChessGame Game;

//Test the start location
    Moves = Game.GetValidMoves(Coordinate(7,1));
    TEST(Moves.size() ==2);
    CONTAINS(5,2);
    CONTAINS(5,0);


//Test to make sure it gets most of the moves and doesn't kill a friendly;
    Game.Move(Coordinate(7,1), Coordinate(4,4));
    Game.Move(Coordinate(1,1),Coordinate(2,1));	//just to toggle the move back

    Moves = Game.GetValidMoves(Coordinate(4,4));


    TEST(Moves.size() == 6);
    CONTAINS(5,2);
    CONTAINS(5,6);
    CONTAINS(2,5);
    CONTAINS(3,6);
    CONTAINS(2,3);
    CONTAINS(3,2);

//Same test, but this time will make sure it selects the squares behind and enemy squares
    Game.NewGame();

    Game.Move(Coordinate(7,1), Coordinate(3,4));
    Game.Move(Coordinate(1,1),Coordinate(2,1));	//just to toggle the move back

    Moves = Game.GetValidMoves(Coordinate(3,4));


    TEST(Moves.size() == 8);
    CONTAINS(4,2);
    CONTAINS(4,6);
    CONTAINS(1,5);
    CONTAINS(2,6);
    CONTAINS(1,3);
    CONTAINS(2,2);

    if (success)
        os<<"		Passed!"<<endl;
    return success;
}
