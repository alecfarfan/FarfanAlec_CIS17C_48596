/***************************************************************************//**
 * \class King King.h "King.h" 
 * The King class represents pieces of the checkerboard which have been 'kinged'
 * Player one (White) has kings that appear as the character 'M' and player two 
 * (Black) has kings that appear as the character 'W'. Kings can move backwards    
 * and forward on the board, therefore the pointer arithmetic is the same for  
 * both the white and black kings. The King class has its own function for  
 * validating it's move, but shares the valPick move with whatever regular 
 * checker class is calling it. Aside from that one function, the King class 
 * contains all of the functions responsible for moving the king around the 
 * board.                                          
 ******************************************************************************/

#include <string>

#ifndef KING_H
#define	KING_H

#include "GamePiece.h"

class Board;

class King: public GamePiece{
    
    public:
        
           King(char);
           virtual char getShow();
           virtual void valPick(string,Board&,char,char,char&,int&);
           virtual bool chkPick(Board&,char,char,char&,int);
           virtual void valMove(string,Board&,char,char,char,char,int&,int);
           virtual bool chkMove(Board&,char,char,char,int,int);
           
};

#endif	/* KING_H */