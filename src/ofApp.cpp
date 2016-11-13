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
    
     std::cout << "original valid x:" << validA << std::endl;
       std::cout << "original valid y:" << validB << std::endl;
    std::cout << "original to move y:" << toMoveB << std::endl;
    std::cout << "original to move y:" << toMoveA << std::endl;
    
}


void ofApp::update()
{
    
}




void ofApp::draw()
{
    ofDrawBitmapStringHighlight(ColorToString(game.GetTurn()), 20, 20);
    
    
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
}
    void ofApp::mouseMoved(int x, int y ){
        
        ofPoint mousePosition(x, y);
        points.push_back(mousePosition);
        
        int a = ofMap(mousePosition.x, 0, 800, 0, 8, true);
        int b = ofMap(mousePosition.y, 0, 800, 0, 8, true);
   
        
        
    }
    void ofApp::mousePressed(int x, int y, int button){
        if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
            
            ofPoint mousePosition(ofGetMouseX(), ofGetMouseY());
            points.push_back(mousePosition);
            
            int a = ofMap(mousePosition.x, 0, 800, 0, 8, true);
            int b = ofMap(mousePosition.y, 0, 800, 0, 8, true);
//                         game.Move(Coordinate(a, b), Coordinate(toMoveB, toMoveA));
            std::cout << "x:" << a << std::endl;
            std::cout << "y:" << b << std::endl;
            set<Coordinate> validMoves = game.GetValidMoves(Coordinate(b, a));
            
            std::cout << "Valid moves ... " << validMoves.size() << std::endl;
            for (Coordinate move: validMoves)
                
            {
                std::cout << move.GetX() << " / " << move.GetY() << std::endl;
                int validA = move.GetX();
                int validB = move.GetY();
                std::cout << "valid x:" << validA << std::endl;
                std::cout << "valid y:" << validB << std::endl;
            }
        }
        
        if(ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
            
            ofPoint mousePosition(ofGetMouseX(), ofGetMouseY());
            points.push_back(mousePosition);
            
            int toMoveB = ofMap(mousePosition.x, 0, 800, 0, 8, true);
            int toMoveA = ofMap(mousePosition.y, 0, 800, 0, 8, true);
            std::cout << "to move x:" << toMoveA << std::endl;
            std::cout << "to move y:" << toMoveB << std::endl;
    
          
            
            
            if(toMoveA == validA and toMoveB == validB)
           std::cout << "It works!" << std::endl;
            
        }
//     game.Move(Coordinate(b, a), Coordinate(toMoveB, toMoveA));
    
    }


            
             

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::keyPressed(int key){
//    if (key == 'q')
//        game.Move(Coordinate(6, 1), Coordinate(4, 1));
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}


