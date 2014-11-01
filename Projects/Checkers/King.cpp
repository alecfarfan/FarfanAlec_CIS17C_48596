/*!
 * Name: Alec Farfan    
 * Date: 04/07/14   
 * Purpose: Functions of the King class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
using namespace std;

// Include header files
#include "King.h"
#include "Board.h"
#include "GamePiece.h"

King::King(char a): GamePiece(){
/***************************************************************************//**
 * This function is the constructor for the King class. The constructor is
 * used to create a king checker. This class inherits from the abstract base
 * class GamePiece whose constructor is called. 
 ******************************************************************************/
    
    // Assign the checker the character passed into the function
    val = a;
    
}
char King::getShow(){
/***************************************************************************//**
 * 
 * 
 ******************************************************************************/
    
    return val;
    
}
void King::valPick(string,Board&,char,char,char&,int&){
/***************************************************************************//**
 * 
 * 
 ******************************************************************************/
    
}
bool King::chkPick(Board&,char,char,char&,int){
/***************************************************************************//**
 * 
 * 
 ******************************************************************************/            
}
void King::valMove(string choice,Board& gameBoard,char gPiece,char gPieceO,char kPieceO,char bPiece,int& coordM,int coordS){
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
        cout<<"PLAYER "<<endl;
        cout<<"Select a square to jump to"<<endl;
        flag=false;                          // Set the flag to false each check
        coordM=gameBoard.getChoice(choice,coordM);       // Get the input from the user
        if(!(chkMove(gameBoard,bPiece,gPieceO,kPieceO,coordS,coordM))){ // Verify that move is valid
            flag=true;
            cout<<"Error! Must move one square in a "<<endl;
            cout<<"forward and diagonal direction."<<endl;}     
     }while(flag==true);
     swap(gameBoard.square[coordS],gameBoard.square[coordM]);

}
bool King::chkMove(Board& gameBoard,char bPiece,char gPieceO,char kPieceO,int coordS,int coordM){
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
        flag = false;}// Verify that move is in range
    if(coordM!=coordS-7&&coordM!=coordS-9&& // Verify that move is in range
       coordM!=coordS-14&&coordM!=coordS-18&&
       coordM!=coordS+7&&coordM!=coordS+9&&
       coordM!=coordS+14&&coordM!=coordS+18){
        flag = false;}          
    if(coordM==coordS-14||coordM==coordS-18||
       coordM==coordS+14||coordM==coordS+18){// Verify that if a two square hop has been
        if(gameBoard.square[avg]!=gPieceO&&gameBoard.square[avg]!=kPieceO){ 
            flag=false;}} // made, that the opponent's piece is being jumped  
    
    return flag;

}