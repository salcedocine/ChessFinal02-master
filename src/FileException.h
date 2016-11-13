//
// C++ Interface: FileException
//
// Description: Used to throw that a file could not be opened
//
//
// Author: Spencer Stirling Gardner <snppla@saber>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef FILEEXCEPTION
#define FILEEXCEPTION
#include <string>
//Used just as a basic exception class
class FileException
{
public:
    FileException():Message(""){}	//No args
    FileException(std::string File):Message(File){} 	//arg of the file name that could not be read
    std::string GetMessage()
    {
        return Message;    //returns the message
    }


private:
    std::string Message;


};








#endif
