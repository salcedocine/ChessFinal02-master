//
// C++ Implementation: Utils
//
// Description:
//
//
// Author: Spencer Stirling Gardner <snppla@saber>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "Utils.h"
#include <cctype>
#include <cstring>

//inline std::string PieceTypeToString(const PieceType & Type);	//Takes a piece type and converts it to a string
std::string PieceTypeToString(const PieceType & Type)
{
    std::string ReturnString;
    switch (Type)
    {
    case _PAWN:
        ReturnString = "pawn";
        break;
    case _ROOK:
        ReturnString = "rook";
        break;
    case _BISHOP:
        ReturnString = "bishop";
        break;
    case _KNIGHT:
        ReturnString = "knight";
        break;
    case _QUEEN:
        ReturnString = "queen";
        break;
    case _KING:
        ReturnString = "king";
        break;
    default:
        ReturnString = "UNKNOWN";
        break;
    }
    return ReturnString;
}

std::string ColorToString(const PieceColor & Color)
{
    std::string ReturnString;

    switch (Color)
    {
    case _BLACK:
        ReturnString = "black";
        break;

    case _WHITE:
        ReturnString = "white";
        break;
    default:
        ReturnString = "UNKNOWN";
        break;


    }







    return ReturnString;
}

void PutBackString(const std::string & ToPutBack, ifstream & Stream)
{
    using namespace std;
    int top = strlen(ToPutBack.c_str());

    while (top>0)
        Stream.putback(ToPutBack.c_str()[--top]);





}
