#include"Piece.h"
#include"Square.h"

///
Square::Square():PiecePointer(NULL)
{
}
Square::~Square()
{
    RemovePiece();


}
void Square::RemovePiece()
{
    if (PiecePointer !=NULL)
        delete PiecePointer;

    PiecePointer = NULL;
}

void Square::CreatePiece(PieceType Type, PieceColor Color)
{
    switch (Type)
    {
    case _PAWN:
        PiecePointer = new Pawn(Color);
        break;
    case _BISHOP:
        PiecePointer = new Bishop(Color);
        break;
    case _ROOK:
        PiecePointer = new Rook(Color);
        break;
    case _KING:
        PiecePointer = new King(Color);
        break;
    case _KNIGHT:
        PiecePointer = new Knight(Color);
        break;
    case _QUEEN:
        PiecePointer = new Queen(Color);
        break;
    default:
        PiecePointer =NULL;
        break;

    }
}

Piece * Square::GetPiece() const
{
    return PiecePointer;
}

void Square::SetPiece(Piece * NewPointer)
{
    PiecePointer = NewPointer;

}
