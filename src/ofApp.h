#pragma once


#include "ofMain.h"
#include "ChessGame.h"
#include "Utils.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    Coordinate getCoordinateForMouse(int x, int y);

    // -1, -1
    Coordinate selectedPiece;
    set<Coordinate> validMoves;

    ChessGame game;

};
