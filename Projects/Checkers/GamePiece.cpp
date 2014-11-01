/*!
 * Name: Alec Farfan    
 * Date: 06/03/14   
 * Purpose: Functions of the GamePiece class 
 */

// Include libraries
#include <iostream>
#include <cstdlib>
using namespace std;

// Include libraries
#include "GamePiece.h"
#include "Board.h"

void GamePiece::chkDub(Board& gameBoard,char gPiece,char gPieceO,char kPieceO,char bPiece,int coordM,int& p1Pieces){
/***************************************************************************//**
 * This function checks to see if after making a capture another jump is within
 * range. Then the user is asked if they would like to take the second hop and
 * if so, the pieces are swapped.  
 ******************************************************************************/
    
    // Declare a variable to hold the user's choice
    char choice;
    
    // Check to see if a double jump is available in an up one and left one move
    if((gameBoard.square[coordM+7]==gPieceO||gameBoard.square[coordM+7]==kPieceO)&&gameBoard.square[coordM+14]==bPiece){
        // If a move is found ask the user if they would like to take the jump
        cout<<"Would you like to make a double jump?"<<endl;
        cout<<"Enter y for yes or n for no"<<endl;
        cout<<"Enter:";
        cin>>choice;
        
        // If so hop over the second piece and make the changes in the board
        if(choice=='y'){
            swap(gameBoard.square[coordM],gameBoard.square[coordM+14]);
            gameBoard.remove(gameBoard,bPiece,coordM,coordM+14,p1Pieces);}        
    }
    // Check to see if a double jump is available in an up one and right one move
    if((gameBoard.square[coordM+9]==gPieceO||gameBoard.square[coordM+9]==kPieceO)&&(gameBoard.square[coordM+18]==bPiece)){
        // If a move is found ask the user if they would like to take the jump
        cout<<"Would you like to make a double jump?"<<endl;
        cout<<"Enter y for yes or n for no"<<endl;
        cout<<"Enter:";
        cin>>choice;
        
        // If so hop over the second piece and make the changes in the board
        if(choice=='y'){
            swap(gameBoard.square[coordM],gameBoard.square[coordM+18]);
            gameBoard.remove(gameBoard,bPiece,coordM,coordM+18,p1Pieces);}    
    }
    
}
void GamePiece::swap(char& a,char& b){
/***************************************************************************//**
 * This function updates the display of the board by swapping the character 
 * representing a player's game piece which has been selected, with the  
 * character representing the empty game square that has been chosen to move
 *  the selected game piece to.
 ******************************************************************************/ 
    
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    
}