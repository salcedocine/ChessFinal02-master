//Class used to store x and y


#ifndef COORDINATE
#define COORDINATE


class Coordinate
{
public:
    Coordinate();		//No arg constructor
    Coordinate(int x, int y);		//Constructor of x and y
    Coordinate(const Coordinate & Other); //copy constructor
    Coordinate & operator = (const Coordinate & Other);	//Assignment
    bool operator < (const Coordinate & Other) const;	//Used to compare two coordinates
    bool operator ==(const Coordinate & Other) const;
    int GetX() const;	//Returns the value of x
    int GetY() const;	//Returns the value of y
    void SetX(int a)
    {
        X = a;    //Sets the X value
    }
    void SetY(int a)
    {
        Y = a;    //Sets the Y value
    }
private:

    void Copy(const Coordinate & Other);	//Used for copying
    int X;		//The x axis
    int Y;		//The y axis

};







#endif

