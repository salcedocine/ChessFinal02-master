#include"Move.h"

Move::Move(const PieceType & PM, const PieceColor & PC, const Coordinate & F, const Coordinate & T,bool First, Piece * P):PieceMoved(PM),ColorOfMoved(PC),From(F),To(T), FirstMove(First), Killed(P)
{




}


Move::Move(const Move & Other)
{
    Copy(Other);

}

Move & Move::operator = (const Move & Other)
{
    if (&Other ==this)
        return *this;

    Copy(Other);
    return *this;


}

void Move::Copy(const Move & Other)
{
    PieceMoved = Other.GetPieceMoved();
    From = Other.GetOriginalLoc();
    To = Other.GetDestinationLoc();
    Killed = Other.Killed;
    FirstMove = Other.IsFirstMove();
    ColorOfMoved = Other.ColorMoved();


}


Move::~Move()
{}
