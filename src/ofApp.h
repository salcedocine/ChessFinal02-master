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
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    void keyReleased(int key);
   
    std::vector<ofPoint> points;
    int validA = 0;
    int validB = 1;
    int toMoveA = 2;
    int toMoveB = 3;
    ChessGame game;
};
