#include"Piece.h"
Piece::Piece(const PieceColor & C, const PieceType & T)
{
    Color = C ;
    Type = T;
    Moved = false;

}

Piece::~Piece()
{


}
set<Coordinate>Piece:: GetValidMoves (const Board & GameBoard, const Coordinate & Position) const
{
    set<Coordinate> ReturnSet;
    return ReturnSet ;
}

PieceType Piece::GetType() const
{
    return Type;
}

PieceColor Piece::GetColor() const
{
    return Color;

}
