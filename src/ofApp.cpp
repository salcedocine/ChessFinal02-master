#include "ofApp.h"


void ofApp::setup()
{
    game.NewGame();
    
//    std::cout << PieceTypeToString(game.GetPiece(Coordinate(6, 1))->GetType()) << std::endl;
//    
//    set<Coordinate> validMoves = game.GetValidMoves(Coordinate(6, 1));

//    std::cout << "Valid moves ... " << validMoves.size() << std::endl;
    
//    for (Coordinate move: validMoves)
//    {
//        std::cout << move.GetX() << " / " << move.GetY() << std::endl;
//        
//    }
    
    
//    game.Move(Coordinate(6, 1), Coordinate(4, 1));
    
//     std::cout << "original valid x:" << validA << std::endl;
//       std::cout << "original valid y:" << validB << std::endl;
//    std::cout << "original to move y:" << toMoveB << std::endl;
//    std::cout << "original to move y:" << toMoveA << std::endl;

}


void ofApp::update()
{
    
}




void ofApp::draw()
{

    
    int width = 100;
    int height = 100;
    
    
    for (std::size_t col = 0; col < BOARD_SIZE; col++)
    
        {
        bool isBlack = true;

        if (col % 2 == 0)
        {
            isBlack = false;
        }

            for (std::size_t row = 0; row < BOARD_SIZE; row++)
    
        {
            int currentY = col * width;
            int currentX = row * height;
            
            if (isBlack == true)
            {
                ofSetColor(ofColor::brown);
                isBlack = false;
            }
            else
            {
                ofSetColor(ofColor::gray);
                isBlack = true;
            }
            
           
            ofDrawRectangle(currentX, currentY, width, height);
            
            Coordinate coordinate(col, row);
            
            ofDrawBitmapStringHighlight(ofToString(coordinate.GetX()) + " " + ofToString(coordinate.GetY()), currentX + 20, currentY + 20);


            Piece* piece = game.GetPiece(coordinate);

            if (piece != nullptr)
            {
                std::string pieceNameString = PieceTypeToString(piece->GetType());
                std::string pieceColorString = ColorToString(piece->GetColor());
                
//                ofDrawBitmapStringHighlight(pieceColorString, currentX, currentY);
                
                if (pieceColorString == "black")
                    ofDrawBitmapStringHighlight(pieceNameString, currentX + width / 2, currentY  + height / 2, 0);
                else
                    ofDrawBitmapStringHighlight(pieceNameString, currentX + width / 2, currentY  + height / 2, 255, 0);


            
            
            }
            
        }
    }

    ofDrawBitmapStringHighlight(ColorToString(game.GetTurn()), 20, 20);

//    cout << points.size() << endl;
}


void ofApp::mousePressed(int x, int y, int button)
{
    // Get the current coordinate for the mouse.
    Coordinate coordinate = getCoordinateForMouse(x, y);

    validMoves = game.GetValidMoves(coordinate);

    if (validMoves.size() > 0)
    {
        selectedPiece = coordinate;
    }
    else
    {
        selectedPiece = Coordinate(-1, -1);
    }
}



void ofApp::mouseReleased(int x, int y, int button)
{
    if (selectedPiece.GetX() >= 0 && selectedPiece.GetY() >= 0)
    {
        Coordinate coordinate = getCoordinateForMouse(x, y);

        for (Coordinate move: validMoves)
        {
            if (coordinate == move)
            {
                // make the move and jump out of the loop ...
                game.Move(selectedPiece, coordinate);
                break;
            }
        }

        selectedPiece = Coordinate(-1, -1);
        validMoves.clear();
    }
}


Coordinate ofApp::getCoordinateForMouse(int x, int y)
{
    int a = ofMap(x, 0, ofGetWidth(), 0, BOARD_SIZE, true);
    int b = ofMap(y, 0, ofGetHeight(), 0, BOARD_SIZE, true);
    return Coordinate(b, a);
}


