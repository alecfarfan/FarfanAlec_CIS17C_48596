/***************************************************************************//**
 * \class GameTree GameTree.h "GameTree.h" 
 * The GameTree class is a tree data structure used to hold all the possible 
 * moves from a given position up to a given depth. The tree is filled with 
 * State objects which contain the current state of the game board as well as
 * numeric scores based on the utility of that position. This class applies the
 * AI's minimax algorithm by searching the tree for the best move by finding the
 * sequence of moves which leads to the highest utility. The minimax algorithm
 * assumes the player opposing the computer is going to play their optimal move.
 * The depth limit of the search is set at six, effectively looking into the 
 * future three moves each for both players.                                               
 ******************************************************************************/

#ifndef GAMETREE_H
#define	GAMETREE_H

// Include libraries
#include <string>

// Include headers
#include "State.h"
#include "Board.h"
#include "Stack.h"
#include "Queue.h"

class GameTree{
    
    private:
    
        struct Node{
            State *current;
            Queue<std::string> moves;
            Node **children;
            int numChildren;
            
        };
        Node *root;
        
        void insert(Node*&,int);
        void makeDeletions(Node*&);
        
    public:
        
        GameTree(Board&);
        ~GameTree();
        void insertNode(Node*);
        void getMoves(Node*);
        void getLegals(Node*,int);
        std::string getCoords(int);
        std::string miniMaxDecision();
        int miniMaxValue(Node*,int,int);
        
};

#endif	/* GAMETREE_H */