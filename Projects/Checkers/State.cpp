/*!
 * Name: Alec Farfan    
 * Date: 06/03/14   
 * Purpose: Functions of the State class
 */

// Include libraries
#include <cstdlib>
#include <iostream>

// Include headers
#include "State.h"

State::State(Board& a):Board(a){
/***************************************************************************//**
 * This function is the default constructor for the State class. A Board object  
 * is passed into the function and then is passed to the copy constructor of the 
 * base class.
 ******************************************************************************/
    
}
State::State(Board& gameBoard,std::string coordS,std::string coordM,int depth):Board(gameBoard){
/***************************************************************************//**
 * This function is the constructor of the State class used in the generation of
 * the game tree. The Board object passed into the parameters is then passed to
 * the copy constructor of the base class. The appropriate changes in the board
 * are immediately applied to the new State object's game board. Finally the
 * utility function is applied giving the game state a numeric score.  
 ******************************************************************************/
    
    // Declare variables to hold the indexes of the coordinates
    int a = 0,b = 0;
 
    // Convert the coordinates from strings to integers
    a = getChoice(this,coordS,a); // Get the index of the square selected
    b = getChoice(this,coordM,b); // Get the index of the square moved to
   
    // Make the swap in the game board
    swap(square[a],square[b]);
    
    // Also record the current depth as well as the two coordinates 
    this->depth = depth;   // Record the current depth
    this->coordS = coordS; // Record the coordinate selected
    this->coordM = coordM; // Record the coordinated moved to
    score = utility();     // Calculate the numeric score of the game state
    
    // Make any appropriate removals of pieces hopped over
    remove(*this,a,b);
    
}
int State::getChoice(State* obj,std::string coord,int index){
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
        coord.copy(array,SIZE); // Copy the string into an array
        
        // Convert from ascii to an integer 
        if(*(array+0)>64&&*(array+0)<97){ // If first coordinate is uppercase,
            index=(((*(array+0)-65)*8)+(*(array+1)-48));} // subtract 65. 
        else{                                               // If lowercase,
            index=(((*(array+0)-97)*8)+(*(array+1)-48));} // subtract 97
        
    }while(flag==true);
    
    delete [] array;
    return index;
    
}
void State::remove(State& gameBoard,int coordS,int coordM){
/***************************************************************************//**
 * This function is used to remove game pieces that have been hopped over in 
 * the generation of a game state. This function overrides the remove function
 * from the base class hence the State object passed in as the first parameter
 ******************************************************************************/ 
    
    int avg = (coordS+coordM)/2; // Take the average of the two coordinates
    char empty = '+';            // Variable to hold the empty square character
    
    // Check to see if a piece has been jumped and captured
    if(coordS==coordM-14||coordS==coordM-18||
       coordS==coordM+14||coordS==coordM+18){ // If so fill the square with an
        swap(gameBoard.square[avg],empty);    // empty board character '+'

    }
    
}
void State::print(){
/***************************************************************************//**
 * This function is not used in the game of checkers, it is primarily for 
 * testing purposes. The function prints the array representing the game board 
 * of the State object calling it. Calling this function while the tree is 
 * generating at a certain depth gives a good view of what moves are available 
 ******************************************************************************/    
   
    // Run through the array and print the contents of each element
    for(int i=1;i<65;i++){
        std::cout<<square[i]<<" "; // Spaces between the elements
        if((i-1)%8==7){            // 8 characters per line
            std::cout<<std::endl;
        }
    }
    
}
float State::utility(){
/***************************************************************************//**
 * This function calculates and assigns a numeric score for each game state that
 * is generated. All the functions used to improve heuristics are called from
 * this function, contributing to the final score of the game state. After the
 * total is calculated the score is stored in the State object. 
 ******************************************************************************/
    
    int value = 0; // Variable to hold the numeric value for the State's score
    int dummy;       // Dummy variable to be plugged into the getChoice function
    
    // Apply points based on safety of grid position
    if(getChoice(this,coordM,dummy)%8==1||getChoice(this,coordM,dummy)%8==0){
        value = 9 * depth; // Highest points for squares on the edge rows
    }
    else if(getChoice(this,coordM,dummy)%8==2||getChoice(this,coordM,dummy)%8==7){
        value = 6 * depth; // Second highest for squares touching edge squares
    }
    else if(getChoice(this,coordM,dummy)%8==3||getChoice(this,coordM,dummy)%8==6){
        value = 4 * depth; // Third highest for squares two in from the edge
    }
    else if(getChoice(this,coordM,dummy)%8==4||getChoice(this,coordM,dummy)%8==5){
        value = 2 * depth; // Lowest points for squares in the middle area
    }
    
    // Apply extra points to a state where a capture was recently made
    if(((getChoice(this,coordM,dummy))-(getChoice(this,coordS,dummy)))>13){
        value += (25 * (depth+1));
    }
    // Subtract points when a move makes a piece suseptible to capture
    if((this->square[(getChoice(this,coordM,dummy)+7)]=='O')
        &&(this->square[(getChoice(this,coordM,dummy)-7)]=='+')||
       (this->square[(getChoice(this,coordM,dummy)+9)]=='O')
        &&(this->square[(getChoice(this,coordM,dummy)-9)]=='+')){
        
        // Subtract off points
        value -= (20 * (depth));
    
    }
    
    return value;
    
}
State State::operator=(State& right){
/***************************************************************************//**   
 * This function overloads the assignment operator '=' for the State class. When
 * an assignment is made from one State object to another only the character
 * array representing the game board is copied over.
 ******************************************************************************/
    
    // Run through the array and copy the contents element for element
    for(int i=1;i<65;i++){
        this->square[i] = right.square[i];
    }
    
    return *this;
    
}