/***************************************************************************//**
 * \class GamePiece GamePiece.h "GamePiece.h" 
 * The GamePiece class is an abstract base class representing a general game 
 * piece to be used in a game of checkers. The class contains five virtual 
 * functions for selecting and validating choices of: game squares for initial
 * selecting of a piece, and moving the piece to the new square. Three classes
 * are derived from GamePiece; RegBlack,RegWhite,and King. Each of these three
 * classes require their own unique pointer arithmetic in order to give them
 * the proper functionality with respect to their place in the game. Two non
 * virtual methods are included also for checking for a double jump and swapping
 * characters.               
 ******************************************************************************/

#ifndef GAMEPIECE_H
#define	GAMEPIECE_H

#include "Board.h"

class GamePiece{
    
    protected:
      
        char val;
    
    public:
        
        GamePiece(){}
        virtual void valPick(string,Board&,char,char,char&,int&) = 0;
        virtual bool chkPick(Board&,char,char,char&,int) = 0;
        virtual void valMove(string,Board&,char,char,char,char,int&,int) = 0;
        virtual bool chkMove(Board&,char,char,char,int,int) = 0;
        virtual char getShow() = 0;
        static void chkDub(Board&,char,char,char,char,int,int&);
        static void swap(char&,char&);
        
};

#endif	/* GAMEPIECE_H */