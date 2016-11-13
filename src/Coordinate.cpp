#include"Coordinate.h"
#include<assert.h>

Coordinate::Coordinate(int a, int b): X(a), Y(b)
{
    assert(a>=0 || a ==-1);
    assert(b>=0 || a==-1);
    assert(a<8);
    assert(b<8);

}
Coordinate::Coordinate(): X(-1), Y(-1)
{}

int Coordinate::GetX() const
{
    return X;
}

int Coordinate::GetY() const
{
    return Y;
}

Coordinate & Coordinate::operator = (const Coordinate & Other)
{
    if (&Other ==this)
        return *this;
    Copy(Other);

    return *this;
}

Coordinate::Coordinate(const Coordinate & Other)
{

    Copy(Other);

}

void Coordinate::Copy(const Coordinate & Other)
{

    X = Other.X;
    Y = Other.Y;

}
bool Coordinate:: operator<(const Coordinate & Other) const
{
    if (X<Other.X)		//First sort to X
        return true;
    else if (X > Other.X)	//Well if the other x is lesser..
        return false;
    //So The x's are equal. now to compare the y's
    if (Y< Other.Y)		//If this y is < the other
        return true;
    else
        return false;	//Catches if the other >= to  this y


}
