/*!
 * \mainpage Alec Farfan
 * Name: Alec Farfan              <br>
 * Date: 06/03/14                 <br>
 * Purpose: Project II (Checkers AI)  <br>
 * <br>
 * Checkers (also known as Draughts) is a two person strategy game where players
 * compete against each other by moving along a diagonal axis, capturing each
 * others pieces by jumping over them. The object of the game is to capture all
 * the opponents game pieces or block them from being able to make any valid 
 * moves. The game is played on an 8 x 8 grid with alternating white and black 
 * squares across each row. The game checkers is what is called a solved game,
 * which means that a particular game's outcome can be predicted from any 
 * position granted both players play with optimum strategy. Checkers AIs like
 * Chinook can play better than the top ranked human players.
 */

//Include libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// Include header files
#include "Board.h"
#include "GamePiece.h"
#include "RegWhite.h"
#include "RegBlack.h"
#include "King.h"
#include "State.h"
#include "GameTree.h"
#include "Stack.h"
#include "Queue.h"

// No global variables or constants

// Function prototypes
void doAgain(char&);
void pVSc();
void pVSp();
void getRules(fstream&);
char menu(char);

// Execution begins here
int main(int argc, char** argv) {
  
    // Declare control loop variable
    char num;
    
    do{
        // Declare stream variables
        fstream rules, errors;
        
        // Output the title screen and ask user to execute a program
        num = menu(num);    // Get a user's choice (char)
        int dummy = num - 48; // then convert it to an integer
        
        // Execute the chosen case
        switch(dummy){
            case 1: pVSp();          // Player vs Player
                    break;
            case 2: pVSc();          // Player vs Computer
                    break;
            case 3: getRules(rules); // Print the rules of the game
                    break;
        }      
    // End program when a non valid value is entered  
    }while(num-48==3||num-48==2||num-48==1);
    
    // End of program
    return 0;
    
}
char menu(char num){
/***************************************************************************//**
 * This function serves as the main menu for the entire program. A char
 * value(when converted to an integer) of either 1 or 2 will execute the
 * game or rules respectively. Any other value will allow the user to exit
 ******************************************************************************/
    
    cout<<"_________________________________________________________________________________"<<endl;
    cout<<"|    ______   __   __   ______   ______   __  __   _______   ______   ______    |"<<endl;
    cout<<"|   |  ____| | |   | | |  ____| |  ____| | | / /  |  _____| |  __  | |  ____|   |"<<endl;
    cout<<"|   | |      | |___| | | |__    | |      | |/ /   | |____   | |__| | | |____    |"<<endl;
    cout<<"|   | |      |  ___  | |  ___|  | |      |  _ \\   |  ____|  |  _ \\/  | ____ |   |"<<endl;
    cout<<"|   | |____  | |   | | | |____  | |____  | | \\ \\  | |_____  | | \\ \\   ____| |   |"<<endl;
    cout<<"|   |______| |_|   |_| |______| |______| |_|  \\_\\ |_______| |_|  \\_\\ |______|   |"<<endl;
    cout<<"|                                                                               |"<<endl;
    cout<<"|                                                                               |"<<endl;
    cout<<"|                 _______________________________________                       |"<<endl;
    cout<<"|                | Enter the number corresponding to the |                      |"<<endl;
    cout<<"|                | selection you would like to choose.   |                      |"<<endl;
    cout<<"|                |_______________________________________|                      |"<<endl;
    cout<<"|                |    1. Player vs Player                |                      |"<<endl;
    cout<<"|                |    2. Player vs Computer              |                      |"<<endl;
    cout<<"|                |    3. Rules                           |                      |"<<endl;   
    cout<<"|                |                                       |                      |"<<endl;
    cout<<"|                |    Enter anything else to exit.       |                      |"<<endl;
    cout<<"|                |_______________________________________|                      |"<<endl;
    cout<<"|                 Enter:";
    cin>>num;
    
    system("CLS");
    return num;
    
}
void getRules(fstream& iFile){
/***************************************************************************//** 
 * This function opens a .dat file with text in it describing all the rules
 * for the game of checkers. The file is read to a string and then outputted
 * to the screen. The user may then exit the rules when ready.
 ******************************************************************************/
       
    int done; // Control loop variable
    
    do{
        system("CLS"); // Close the screen before outputting the rules text
        iFile.open("Rules.dat",ios::in); // Open the file
        
        while(iFile.good()){   
            string read;            // String to hold the text
            getline(iFile,read);    // Read the text into the string  
            cout<<read<<endl; // Print the string to the screen
        }
        cout<<endl;
        iFile.close();          // Close the file
        
        // Allow user to return to menu when done reading
        cout<<"Enter 1 to return to the menu:";
        cin>>done;
        
    }while(done!=1);
    
}
void pVSp(){
/***************************************************************************//**
 * This function is the container for the whole game, function will continue
 * to loop until the user has indicated that they would like to exit and 
 * return to the main menu.
 ******************************************************************************/
    
    // Declare control loop variable
    char repeat;
    
    do{
        // Declare variables
        char gPiece1 = 'O', gPiece2 = 149; // Characters for regular game pieces
        Board gameBoard;
        RegBlack blackKey(149);            // Black checker piece for testing
        RegWhite whiteKey(gPiece1);            // White checker piece for testing
        King kingKey(' ');                 // King checker piece for testing
        char bPiece1 = '-', bPiece2 = '+'; // Characters for board pieces
        char kPiece1 = 'M', kPiece2 = 'W'; // Characters for king game pieces
        char used;                         // Character to hold the piece used
        int p1Pieces = 12, p2Pieces = 12;  // Count of player's game pieces
        bool winner = false;               // Boolean value to end the game
        int coordS = 0, coordM = 0;        // Coordinate selected and moved
        string choice;                     // String for coordinate choice
        
        // Create, fill, and print the checkerboard
        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
      
        while(winner==false){
          
            // Player 1's Turn
            if(!(winner)){        
                GameTree *test = new GameTree(gameBoard);
    
                // Get a valid selection of a game piece and redisplay the board
                whiteKey.valPick(choice,gameBoard,gPiece1,kPiece1,used,coordS);
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                // Get a valid move to a game square and change the board
                if(used==gPiece1){
                    whiteKey.valMove(choice,gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,coordS);
                if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p2Pieces))){
                    gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                    RegWhite::chkDub(gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,p2Pieces);  
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                if(used==kPiece1){
                    kingKey.valMove(choice,gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,coordS);
                    if(gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p2Pieces)){   
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                      King::chkDub(gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,p2Pieces);  
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                    // Redisplay the board and then check for a win
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                whiteKey.chkKing(gameBoard,gPiece1,kPiece1,gPiece2,p1Pieces,p2Pieces);
                gameBoard.chkWin(winner,p1Pieces,p2Pieces);
            }
            // Player 2's Turn
            if(!(winner)){
                // Get a valid selection of a game piece and redisplay the board
                blackKey.valPick(choice,gameBoard,gPiece2,kPiece2,used,coordS);
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                // Get a valid move to a game square and change in the board
                if(used==gPiece2){
                    blackKey.valMove(choice,gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,coordS);
                    if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p1Pieces))){
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                        RegBlack::chkDub(gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,p1Pieces);  
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }    
                if(used==kPiece2){
                    kingKey.valMove(choice,gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,coordS);
                    if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p1Pieces))){
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                      King::chkDub(gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,p1Pieces);  
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                // Redisplay the board and then check for a win
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                blackKey.chkKing(gameBoard,gPiece2,kPiece2,gPiece1,p1Pieces,p2Pieces);
                gameBoard.chkWin(winner,p1Pieces,p2Pieces);
            }
        } 
        
        // Ask user if the user would like to repeat the program
        doAgain(repeat);
    }while(repeat=='Y'||repeat=='y');
    
}
void pVSc(){
/***************************************************************************//**
 * This function is the container for the whole game, function will continue
 * to loop until the user has indicated that they would like to exit and 
 * return to the main menu.
 ******************************************************************************/
    
    // Declare control loop variable
    char repeat;
    
    do{
        // Declare variables
        char gPiece1 = 'O', gPiece2 = 149; // Characters for regular game pieces
        Board gameBoard;
        RegBlack blackKey(149);            // Black checker piece for testing
        RegWhite whiteKey(gPiece1);        // White checker piece for testing
        King kingKey(' ');                 // King checker piece for testing
        char bPiece1 = '-', bPiece2 = '+'; // Characters for board pieces
        char kPiece1 = 'M', kPiece2 = 'W'; // Characters for king game pieces
        char used;                         // Character to hold the piece used
        int p1Pieces = 12, p2Pieces = 12;  // Count of player's game pieces
        bool winner = false;               // Boolean value to end the game
        int coordS = 0, coordM = 0;        // Coordinate selected and moved
        string choice;                     // String for coordinate choice
        
        // Create, fill, and print the checkerboard
        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
             
        while(winner==false){
          
            // Player 1's Turn
            if(!(winner)){        
    
                // Get a valid selection of a game piece and redisplay the board
                whiteKey.valPick(choice,gameBoard,gPiece1,kPiece1,used,coordS);
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                // Get a valid move to a game square and change the board
                if(used==gPiece1){
                    whiteKey.valMove(choice,gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,coordS);
                if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p2Pieces))){
                    gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                    RegWhite::chkDub(gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,p2Pieces);  
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                if(used==kPiece1){
                    kingKey.valMove(choice,gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,coordS);
                    if(gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p2Pieces)){   
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                      King::chkDub(gameBoard,gPiece1,gPiece2,kPiece2,bPiece2,coordM,p2Pieces);  
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                    // Redisplay the board and then check for a win
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                whiteKey.chkKing(gameBoard,gPiece1,kPiece1,gPiece2,p1Pieces,p2Pieces);
                gameBoard.chkWin(winner,p1Pieces,p2Pieces);
            }
            // Computer's Turn
            if(!(winner)){
                GameTree *gametree = new GameTree(gameBoard);
                string choice = gametree->miniMaxDecision();
                
                string a,b;
                a += choice[0];
                a += choice[1];
                b += choice[2];
                b += choice[3];
                
               // if(used==gPiece2){
                    blackKey.aiMove(gameBoard,a,b,coordS,coordM);
                    if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p1Pieces))){
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                       // RegBlack::chkDub(gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,p1Pieces);  
                        gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
               // }    
                if(used==kPiece2){
                    kingKey.valMove(choice,gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,coordS);
                    if((gameBoard.remove(gameBoard,bPiece2,coordS,coordM,p1Pieces))){
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                      King::chkDub(gameBoard,gPiece2,gPiece1,kPiece1,bPiece2,coordM,p1Pieces);  
                      gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);}
                }
                // Redisplay the board and then check for a win
                gameBoard.display(gPiece1,gPiece2,p1Pieces,p2Pieces);
                blackKey.chkKing(gameBoard,gPiece2,kPiece2,gPiece1,p1Pieces,p2Pieces);
                gameBoard.chkWin(winner,p1Pieces,p2Pieces);
                
            }
        } 
        
        // Ask user if the user would like to repeat the program
        doAgain(repeat);
    }while(repeat=='Y'||repeat=='y');
    
}
void doAgain(char& repeat){
/***************************************************************************//**
 *  This function executes after a game has been won and asks the user if
 * they would like to play another game or return to the menu. The screen
 * is cleared after the repeat variable is read in.
 ******************************************************************************/ 
    
    cout<<"Would you like to repeat the program? Enter Y to"<<endl;
    cout<<"repeat or enter anything else to return to the menu:";
    cin>>repeat;
    system("CLS");    
    
}