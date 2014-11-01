/*!
 * Name: Alec Farfan    
 * Date: 04/07/14   
 * Purpose: Functions of the RegWhite class
 */

// Include libraries
#include <iostream>
#include <cstdlib>
using namespace std;

// Include header files
#include "RegWhite.h"
#include "Board.h"
#include "GamePiece.h"

RegWhite::RegWhite(char a):GamePiece(){
/***************************************************************************//**
 * This function is the constructor for the RegWhite class. The constructor is
 * used to create a regular white checker. This class inherits from the abstract
 * base class GamePiece whose constructor is called. 
 ******************************************************************************/
    
    // Assign the checker the character passed into the function
    val = a;
    
}
char RegWhite::getShow(){
/***************************************************************************//**
 * Accessor function for the regular black checker, returns the char variable 
 * named show, value of 149 representing a black bullet like character
 ******************************************************************************/
    
    return val;
    
}
void RegWhite::valPick(string choice,Board& gameBoard,char gPiece,char kPiece,char& used,int& coordS){
/***************************************************************************//**
 * This function determines which players turn it is and keeps prompting for
 * a coordinate choice until a valid pick is made. The valid pick is stored
 * in the coordS reference variable. This is one of two functions
 * responsible for validating input in terms of what is legal within the 
 * rules of the game, the other is valMove
 ******************************************************************************/

    // Declare flag variable
    bool flag;
    
    // Keep calling the getChoice function until a valid selection is made
    do{
       cout<<"PLAYER 1"<<endl;
       cout<<"Select one of your game pieces"<<endl;
       flag=false;                           // Set the flag to false each check
       coordS=gameBoard.getChoice(choice,coordS);      // Get the input from the user
       if(!(chkPick(gameBoard,gPiece,kPiece,used,coordS))){ // Verify that move is valid
           flag=true;
           cout<<"Error! Must choose one's own gamepiece"<<endl;}
    }while(flag==true);

}
bool RegWhite::chkPick(Board& gameBoard,char gPiece,char kPiece,char& used,int element){
/***************************************************************************//**
 * This function checks the selection made by a player and determines if it 
 * is valid. In order for the selection to be valid the array element of 
 * that coordinate must contain that particular player's piece in it. 
 ******************************************************************************/    
   
    // Declare flag variable
    bool valid;
    
    // Verify element contains player's piece, if so the selection is valid.
    if(gameBoard.square[element]==gPiece){     // Check for a regular checker
        valid = true;                   
        valid = true;              
        used = gPiece;}
    else if(gameBoard.square[element]==kPiece){ // Check for a king checker
        valid = true;
        used = kPiece;}
    
    return valid;
    
}
void RegWhite::valMove(string choice,Board& gameBoard,char gPiece,char gPieceO,char kPieceO,char bPiece,int& coordM,int coordS){
/***************************************************************************//** 
 * This function determines which players turn it is and keeps prompting for
 * a coordinate choice until a valid move is made. The valid move is stored
 * in the coordM reference variable. In order for a move to be valid the
 * move must be in a forward and diagonal motion of one space if not 
 * jumping, and two if a capture is made.
 ******************************************************************************/ 
  
   // Declare flag variable
    bool flag;
    
    // Keep calling getChoice until a valid move is made
    do{   
        cout<<"PLAYER 1"<<endl;
        cout<<"Select a square to jump to"<<endl;
        flag=false;                          // Set the flag to false each check
        coordM=gameBoard.getChoice(choice,coordM);     // Get the input from the user
        if(!(RegWhite::chkMove(gameBoard,bPiece
                    ,gPieceO,kPieceO,coordS,coordM))){ // Verify that move is valid
            flag=true;
            cout<<"Error! Must move one square in a "<<endl;
            cout<<"forward and diagonal direction."<<endl;}     
     }while(flag==true);
     swap(gameBoard.square[coordS],gameBoard.square[coordM]);

}
bool RegWhite::chkMove(Board& gameBoard,char bPiece,char gPieceO,char kPieceO,int coordS,int coordM){
/***************************************************************************//** 
 * This function checks to see if the empty game square player two has chosen 
 * to move a selected piece to is a valid move. If no piece is being 
 * captured the move square must be +7 or +9 squares away from. If a piece is 
 * being captured, then the same rules apply in terms of sign but with the 
 * numbers +14 and +18. Also the square between the selection and the move 
 * needs to contain the opponents game piece in it for it to be valid
 ******************************************************************************/
    
    // Set the flag variable to true and take the average
    int avg=(coordS+coordM)/2;
    bool flag=true;
    
    if(gameBoard.square[coordM]!=bPiece){ // Verify that the move square is empty
        flag = false;}
    if(coordM!=coordS-7&&coordM!=coordS-9&& // Verify that move is in range
       coordM!=coordS-14&&coordM!=coordS-18){
        flag = false;}          
    if(coordM==coordS-14||coordM==coordS-18){ // Verify that if a two square hop has been
        if(gameBoard.square[avg]!=gPieceO&&gameBoard.square[avg]!=kPieceO){
            flag=false;}} // made, that the opponent's piece is being jumped  
    
    return flag;

}
void RegWhite::chkKing(Board& gameBoard,char gPiece,char kPiece,char gPieceO,int p1Pieces,int p2Pieces){
/***************************************************************************//**
 * This function checks to see if player one has made one of their pieces to 
 * the opposite side of the board. If so the square of the board is assigned
 * the character 'W' representing a king and the program lets the users know
 * of the change.
 ******************************************************************************/
    
    // Run through the bottom row of the board
    for(int i=1;i<9;i++){
        // Check to see if a regular white checker has made it to the other side
        if(gameBoard.square[i]==gPiece){
            gameBoard.square[i] = kPiece;// If so turn the checker into a king
            
            // Redisplay the board and notify user's of changes
            gameBoard.display(gPiece,gPieceO,p1Pieces,p2Pieces);
            cout<<"Player 1's piece has been kinged!"<<endl;}
    }
    
}