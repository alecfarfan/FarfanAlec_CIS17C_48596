/***************************************************************************//**
 * \class RegBlack RegBlack.h "RegBlack.h"  
 * The RegBlack class represents the regular black checker which has not been  
 * kinged. Since black checkers start at the top of the board where the index  
 * values start (element 0 ), regular black checkers can only move in plus + 
 * directions. The ascii character 149 which appears as a black bullet is used 
 * to represent a black checker piece. The RegBlack class contains all the 
 * necessary functions to evaluate moves across the board for black checkers.
 * As with all of the checker piece objects, only one needs to be instantiated
 * for the game, which acts as a key to graining access to the game board.    
 ******************************************************************************/

#ifndef REGBLACK_H
#define	REGBLACK_H

#include "GamePiece.h"

class Board;

class RegBlack: public GamePiece{
            
    public:
        RegBlack(char a);
        virtual char getShow();
        virtual void valPick(string,Board&,char,char,char&,int&);
        virtual bool chkPick(Board&,char,char,char&,int);
        virtual void valMove(string,Board&,char,char,char,char,int&,int);
        virtual bool chkMove(Board&,char,char,char,int,int);
        void aiMove(Board&,string,string,int&,int&);
        void chkKing(Board&,char,char,char,int,int);
        
};

#endif	/* REGBLACK_H */