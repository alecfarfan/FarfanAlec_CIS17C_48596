/***************************************************************************//**
 * \class State State.h "State.h" 
 * The State class represents the state of the game at a given position. This
 * classes primary purpose is for use in the AI's decision. The GameTree class
 * creates a tree by filling it up with State objects representing all the     
 * possible legal moves for each player starting from a given position, up to a  
 * certain depth limit. The state class inherits from the Board class and uses
 * its copy constructor in the derived constructor call and then makes the 
 * appropriate changes for each legal move. Then the utility function is applied
 * to give the instance being declared a numeric score to be used in the 
 * minimax decision.                                           
 ******************************************************************************/

#ifndef STATE_H
#define	STATE_H

// Include headers
#include "Board.h"

class State: public Board {
    
    friend class GameTree;
    
    private:
        
        std::string coordS,
                    coordM;
        int depth;
        int turn;
        int score;
        
    public:
        
        State(Board&);
        State(Board&,std::string,std::string,int);   
        int getChoice(State*,std::string,int);
        void remove(State&,int,int);
        void print();
        float utility();
        State operator=(State&);
        
};

#endif	/* STATE_H */