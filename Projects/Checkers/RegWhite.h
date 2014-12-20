/***************************************************************************//**
 * \class RegWhite RegWhite.h "RegWhite.h"  
 * The RegWhite class represents the regular white checker which has not been  
 * kinged. Since white checkers start at the bottom of the board where the index  
 * values approach their max regular black checkers can only move in minus - 
 * directions. An uppercase 'O' character is used to represent a white checker 
 * piece. The RegWhite class contains all the necessary functions to evaluate 
 * moves across the board for white checkers. As with all of the checker piece
 * objects, only one needs to be instantiated for the game, which acts as a key
 * to gaining access to the game board.
 ******************************************************************************/

#ifndef REGWHITE_H
#define	REGWHITE_H


#include <string>
#include "GamePiece.h"

class Board;

class RegWhite: public GamePiece{
    
    public:
        
        RegWhite(char a);
        virtual char getShow();
        virtual void valPick(string,Board&,char,char,char&,int&);
        virtual bool chkPick(Board&,char,char,char&,int);
        virtual void valMove(string,Board&,char,char,char,char,int&,int);
        virtual bool chkMove(Board&,char,char,char,int,int);
        void chkKing(Board&,char,char,char,int,int);
        
};

#endif	/* REGWHITE_H */