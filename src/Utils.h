//
// C++ Interface: Utils
//
// Description: Header file of different funcationsused for chess
//
//
// Author: Spencer Stirling Gardner <snppla@saber>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef UTILS
#define UTILS

#include <string>
#include "Piece.h"
#include <fstream>

std::string PieceTypeToString(const PieceType & Type);	//Takes a piece type and converts it to a string
std::string ColorToString(const PieceColor & Color);	//Takes a color and converts it to a string
void PutBackString(const std::string &, ifstream &);






#endif
