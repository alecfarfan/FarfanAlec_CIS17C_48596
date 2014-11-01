/*!
 * Name: Alec Farfan    
 * Date: 04/07/14   
 * Purpose: Functions of the Board class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
using namespace std;

// Include header files
#include "Board.h"

Board::Board(){
/***************************************************************************//**
 * This function is the constructor for the Board class. Plus '+' and minus '-'
 * signs are painted across the board in a checkerboard image with 'O' and 
 * ascii 149 representing the white and black checkers respectively. 
 ******************************************************************************/
    
    // Declare variables for painting the checkerboard 
    char a = '-', b = '+';
    
    // Run through the array and paint the checkerboard
    for(int i=1;i<65;i++){
        if(i%2==0){       // Assign character a to even squares 
            square[i] = a;}
        else{             // Assign character b to odd squares
            square[i] = b;}
        if((i-1)%8==7){   // Swap characters at the end of the road
            swap(a,b);}
    }
    
    // Put the two players pieces on the checkerboard
    for(int i=0;i<25;i++){  // For the top two rows
        if(square[i]==b){   // check if the square is a valid playing square
            square[i] = 149;} // if so assign it one of player one's game pieces. 
    }
    for(int i=41;i<65;i++){ // For the bottom two rows
        if(square[i]== b){     // check if the square is a valid playing square
            square[i] = 79;}   // if so assign it one of player two's game pieces
    }
        
}
Board::Board(Board& obj){
/***************************************************************************//**    
 * This function is a copy constructor for the Board class. This function is 
 * mainly used to instantiate State objects which are derived from this class. 
 ******************************************************************************/    
   
    // Copy the contents of the array from the Board object passed in
    for(int i=1;i<65;i++){
        this->square[i] = obj.square[i];
    }
    
}
void Board::display(char a,char b,int p1C, int p2C){
/***************************************************************************//** 
 * Function displays a checkerboard made by piecing together strings and
 * nesting an element of the array in each of the squares. Around the board
 * a letter/number coordinate system is drawn to allow the users to point to
 * a game square. To the right of the game board a scoreboard is printed 
 * showing current statuses of the game.
 ******************************************************************************/
    
    //system("CLS"); // Clear the screen each time the function is called
    cout<<"_____________________________________"<<endl;
    cout<<"|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |   PLAYER 1 = "<<a<<" , PLAYER 2 = "<<b<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|   ___________________________"<<endl;
    cout<<"| A | "<<square[1]<<" | "<<square[2]<<" | "<<square[3]<<" | "<<square[4]<<" | "<<square[5]<<" | "<<square[6]<<" | "<<square[7]<<" | "<<square[8]<<" |   |                          |"<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|   |  PLAYER 1: "<<p1C<<"            |"<<endl;
    cout<<"| B | "<<square[9]<<" | "<<square[10]<<" | "<<square[11]<<" | "<<square[12]<<" | "<<square[13]<<" | "<<square[14]<<" | "<<square[15]<<" | "<<square[16]<<" |   |  PLAYER 2: "<<p2C<<"            |"<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|   |                          |"<<endl;
    cout<<"| C | "<<square[17]<<" | "<<square[18]<<" | "<<square[19]<<" | "<<square[20]<<" | "<<square[21]<<" | "<<square[22]<<" | "<<square[23]<<" | "<<square[24]<<" |   |                          |"<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|   |                          |"<<endl;
    cout<<"| D | "<<square[25]<<" | "<<square[26]<<" | "<<square[27]<<" | "<<square[28]<<" | "<<square[29]<<" | "<<square[30]<<" | "<<square[31]<<" | "<<square[32]<<" |   |                          |"<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|   |__________________________|"<<endl;
    cout<<"| E | "<<square[33]<<" | "<<square[34]<<" | "<<square[35]<<" | "<<square[36]<<" | "<<square[37]<<" | "<<square[38]<<" | "<<square[39]<<" | "<<square[40]<<" | "<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"| F | "<<square[41]<<" | "<<square[42]<<" | "<<square[43]<<" | "<<square[44]<<" | "<<square[45]<<" | "<<square[46]<<" | "<<square[47]<<" | "<<square[48]<<" | "<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|"<<endl; 
    cout<<"| G | "<<square[49]<<" | "<<square[50]<<" | "<<square[51]<<" | "<<square[52]<<" | "<<square[53]<<" | "<<square[54]<<" | "<<square[55]<<" | "<<square[56]<<" | "<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"| H | "<<square[57]<<" | "<<square[58]<<" | "<<square[59]<<" | "<<square[60]<<" | "<<square[61]<<" | "<<square[62]<<" | "<<square[63]<<" | "<<square[64]<<" | "<<endl;
    cout<<"|___|___|___|___|___|___|___|___|___|"<<endl;

}
int Board::getChoice(string choice,int element){
/***************************************************************************//** 
 * This function reads in a letter/number coordinate choice from the user 
 * which is then copied into a character array to be manipulated and tested 
 * for validity. The type of validity this function is responsible for 
 * checking is in terms of data format ie. proper size, proper letter/number 
 * entry, ect. The valChoice and valMove functions are responsible for 
 * testing validity in terms of what is legal in the game of checkers. 
 ******************************************************************************/
    
    const int SIZE = 2;            // Size for the copy of the string
    char *array = new char [SIZE]; // Copy string into array for testing
    bool flag;                     // Flag variable for validity result
    
    // Keep prompting for an input until a valid selection is made
    do{
        flag = false; // Set the flag as false at the beginning of each check 
        cout<<"Enter the letter/number coordinates:";
        cin>>choice;             // Read in the input
        choice.copy(array,SIZE); // Copy the string into an array
        
        // Convert from ascii to an integer 
        if(*(array+0)>64&&*(array+0)<97){ // If first coordinate is uppercase,
            element=(((*(array+0)-65)*8)+(*(array+1)-48));} // subtract 65. 
        else{                                               // If lowercase,
            element=(((*(array+0)-97)*8)+(*(array+1)-48));} // subtract 97
        
        // Verify that user inputed at least, but not more than two characters
        if(choice.size()!=2){
            flag=true;
            std::cout<<"Error! Enter a single letter and number ex. 'A1'"<<endl;}
        
        // Verify that the first coordinate is either a letter from A to H
        if((!(*(array+0)>64)||!(*(array+0)<73))&&
             (!(*(array+0)>96)||!(*(array+0)<105))){
            flag=true;
            cout<<"Error! First input must be a letter"<<endl;
            cout<<"from A to H ex. 'A1'"<<endl;}
        
        // Verify that the second coordinate is a number from 1 to 8
        if(!(*(array+1)>48) || !(*(array+1)<57)){
            flag=true;
            cout<<"Error! Second input must be a number"<<endl;
            cout<<"from 1 to 8 ex. 'A1'"<<endl;}
    }while(flag==true);
    
    delete [] array;
    return element;

}
bool Board::remove(Board& gameBoard,char bPiece,int coordS,int coordM,int& count){
/***************************************************************************//** 
 * This function removes a game piece that has been jumped and captured. 
 * The array element holding the game piece that needs to be removed can be 
 * found by taking the average of the coordinate of the selected game piece
 *  and the coordinate of empty game square chosen to move the piece to.
 ******************************************************************************/ 
    
    bool flag;
    int avg = (coordS+coordM)/2; // Take the average of the two 
    
    // Check to see if a piece has been jumped and captured
    if(coordS==coordM-14||coordS==coordM-18||
       coordS==coordM+14||coordS==coordM+18){
        Board::swap(gameBoard.square[avg],bPiece); // Replace the square with empty character
        count--;                 // Decrease the count of player's game pieces
        flag = true;
    }
    
    return flag;

}
void Board::chkWin(bool& win,int p1, int p2){
/***************************************************************************//**
 *  This function checks to see if the game has been won by viewing the     
 *  count of both of the players pieces. If the game is over the message     
 *  stating who the winner is gets printed to the screen.                                           
 ******************************************************************************/
    
    if (p1==0){
        win = true;
        cout<<"PLAYER 2 Wins!"<<endl;}
    
    else if(p2==0){
        win = true;
        cout<<"PLAYER 1 Wins!"<<endl;}

}
void Board::swap(char& a,char& b){
/***************************************************************************//**
 * This function updates the display of the board by swapping the character 
 * representing a player's game piece which has been selected, with the  
 * character representing the empty game square that has been chosen to move
 * the selected game piece to.
 ******************************************************************************/ 
    
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    
}