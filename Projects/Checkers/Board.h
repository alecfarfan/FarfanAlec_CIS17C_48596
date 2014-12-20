/***************************************************************************//**
 * \class Board Board.h "Board.h" 
 * The Board class represents the physical checkerboard that a game of checkers
 * is usually played on. To mimic a checkerboard's black and white squares, 
 * plus + and minus - characters are printed to the board. The classes  
 * representing black checkers, white checkers, and king checkers are friends
 * with this class. The board is changed by these objects by the characters
 * held within them, an object doesn't actually need to be placed on the board.
 * The Board class is responsible for all the tasks involving searching the 
 * board as well as making changes to it.                                                     
 ******************************************************************************/

#ifndef BOARD_H
#define	BOARD_H

// Include libraries
#include <string>

class Board{
    
    friend class GamePiece;
    friend class RegWhite;
    friend class RegBlack;
    friend class King;
    
    protected:
        
            char square[65];
            
    public:
        
           Board();
           Board(Board&);
           void display(char,char,int,int);
           int getChoice(std::string,int);
           static void swap(char&,char&);
           bool remove(Board&,char,int,int,int&);
           void chkWin(bool&,int,int);
           
};

#endif	/* BOARD_H */