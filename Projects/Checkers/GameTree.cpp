 /*!
 * Name: Alec Farfan    
 * Date: 06/03/14   
 * Purpose: Functions of the GameTree class
 */ 

// Include headers
#include "State.h"
#include "GameTree.h"

GameTree::GameTree(Board& start){
/***************************************************************************//**
 * This function is the constructor for the GameTree class. The initial game 
 * state at the beginning of a turn is stored in a root node and is inserted 
 * into the tree.
 ******************************************************************************/
   
    // Create a new node
    Node *nodePtr = new Node;          
    
    // Create a State object and assign it to the node's member 'current'
    nodePtr->current = new State(start);
    nodePtr->current->turn = 0; // Set the initial turn to zero
 
    // Assign the new node to the root of the tree and insert it into the tree
    root = nodePtr;
    insertNode(root);
     
}
GameTree::~GameTree(){
/***************************************************************************//**
 * This function is the destructor of the GameTree class. The function passes
 * the root of the tree to the makeDeletions function which recursively deletes
 * the tree. 
 ******************************************************************************/
    
    // Pass the root of the tree 
    makeDeletions(root);
    
}
void GameTree::insertNode(Node* nodePtr){
/***************************************************************************//**
 * This function passes the root to the insert function which recursively 
 * generates and inserts game states into the tree. The tree is generated up to
 * a given depth passed into the second parameter of the insert function. 
 ******************************************************************************/
    
    // Pass the root of the tree up to a depth of 5
    insert(nodePtr,5);
    
}
void GameTree::insert(Node*& nodePtr,int depth){
/***************************************************************************//**
 * This function takes the root in the initial function call and then 
 * recursively generates nodes of the tree and inserts them up to a given depth
 * passed into the second parameter of this function. 
 ******************************************************************************/
    
    // Get the list of legal moves and store them in the moves queue 
    getMoves(nodePtr);
    
    // If the maximum depth hasn't been reached and legal moves aren't exhausted
    if(depth>0&&nodePtr->numChildren>0){
        // Allocate an array of child nodes     
        nodePtr->children = new Node*[nodePtr->numChildren];
        // Run through the array of nodes inserting the legal moves
        for(int i=0;i<nodePtr->numChildren;i++){
                // Dequeue the two coordinates
                std::string a , b;         
                nodePtr->moves.dequeue(a);
                nodePtr->moves.dequeue(b);
               
                // Create a new node with a state including the change in boards
                Node *temp = new Node;
                temp->current = new State(*(nodePtr->current),a,b,depth);
                temp->current->turn = nodePtr->current->turn + 1;
                
                // Assign the new node to the current element of the node array
                nodePtr->children[i]=temp;
                // Then recursively insert the current element into the tree
                insert(nodePtr->children[i],depth-1);
        }
    }
    
}
void GameTree::makeDeletions(Node*& nodePtr){
/***************************************************************************//**
 * This function takes the root in the initial function call when it is called 
 * by the destructor of the class. The function recursively deletes all the
 * arrays of nodes in the tree. 
 ******************************************************************************/
    
    // Run through the current node's array of child nodes
    for(int i=0;i<nodePtr->numChildren;i++){
        delete nodePtr->children[i]->current;
        makeDeletions(nodePtr->children[i]);
    }
    // If there are multiple child nodes delete them
    if (nodePtr->numChildren>0){
        delete [] nodePtr->children;
    }
    
}
void GameTree::getMoves(Node* nodePtr){
/***************************************************************************//**
 * This function runs through the character array stored in the nodePtr's
 * 'current' data member and finds all the pieces of the player whose turn it is
 * and passes them into the getLegal function to fill the moves Queue data
 * member with all the legal moves for that player. The numChildren variable is
 * set at the end.  
 ******************************************************************************/
    
    // Declare variable to hold character of the game piece to be searched for
    char lookUp;
    
    // If the current state is of an even turn then look for the black checkers
    if(nodePtr->current->turn%2==0){
        lookUp = 149;}
    
    // If the current state is of an odd number then look for the white checkers
    else{
        lookUp = 'O';}
    
    // Run through the board and find the index of each piece and pass it to the
    for(int i=0;i<65;i++){ // getLegals function to fill the queue with moves
        if(nodePtr->current->square[i]==lookUp){          
            getLegals(nodePtr,i);}
    }
    
    // Set the numChildren variable to half the elements of the node array
    nodePtr->numChildren = nodePtr->moves.getSize()/2; // (2 elements = 1 move)
    
}
void GameTree::getLegals(Node* nodePtr,int index){
/***************************************************************************//**
 * This function takes an index and the character array stored in the nodePtr's  
 * 'current' data member and finds all the legal moves from that spot. If a 
 * legal move is found the coordinate of the square selected as well as the 
 * coordinate of the square moved to is popped into the queue as a string. 
 ******************************************************************************/
    
    // If the turn is of an even number then look for the black checkers
    if(nodePtr->current->turn%2==0){
        // Search for the first type of regular move +7
        if(nodePtr->current->square[index+7]=='+'){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index+7));
        }
        // Search for the second type of regular move +9
        if(nodePtr->current->square[index+9]=='+'){
           nodePtr->moves.enqueue(getCoords(index));
           nodePtr->moves.enqueue(getCoords(index+9));
        }
        
        // Search for the first type of jumping move +14
        if(nodePtr->current->square[index+14]=='+'&&nodePtr->current->square[index+7]=='O'){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index+14));
        }
        // Search for the second type of jumping move +18
        if(nodePtr->current->square[index+18]=='+'&&nodePtr->current->square[index+9]=='O'){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index+18));
        }
    }
    
    // If the turn is of an odd number then look for the white checkers
    else{
        // Search for the first type of regular move -7
        if(nodePtr->current->square[index-7]=='+'){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index-7));
        }
        // Search for the second type of regular move +9
        if(nodePtr->current->square[index-9]=='+'){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index-9));
        }
        
        // Search for the first type of jumping move +14
        if(nodePtr->current->square[index-14]=='+'&&nodePtr->current->square[index-7]==149){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index-14));
        }
        // Search for the second type of jumping move +18
        if(nodePtr->current->square[index-18]=='+'&&nodePtr->current->square[index-9]==149){
            nodePtr->moves.enqueue(getCoords(index));
            nodePtr->moves.enqueue(getCoords(index-18));
        }
    }
    
}
std::string GameTree::getCoords(int index){
/***************************************************************************//**
 * This function takes an integer representing the index of the board and  
 * returns the letter/number coordinate in the form of a string so it can be
 * used in the main program
 ******************************************************************************/
    
    // Declare a variables to hold the data
    int letter, number;     // Variables to store letter and number components
    std::string coordinate; // String to store final coordinate 
    
    letter = index / 8;     // Get the letter by integer division
    number = index % 8;     // Get the number by moding the index
    
    // Prevent numbers that mod to 0 from being pushed to the next row
    if(index%8==0){
        letter -= 1;
    }
    
    // Add the letter component to the coordinate string
    switch(letter){
        
        case 0: coordinate += "a";
                break;
        case 1: coordinate += "b";
                break;
        case 2: coordinate += "c";
                break;
        case 3: coordinate += "d";
                break;
        case 4: coordinate += "e";
                break;
        case 5: coordinate += "f";
                break;
        case 6: coordinate += "g";
                break;
        case 7: coordinate += "h";
                break;
        
    }
    // Add the number component to the coordinate string
    switch(number){
        
        case 0: coordinate += "8";
                break;
        case 1: coordinate += "1";
                break;
        case 2: coordinate += "2";
                break;
        case 3: coordinate += "3";
                break;
        case 4: coordinate += "4";
                break;
        case 5: coordinate += "5";
                break;
        case 6: coordinate += "6";
                break;
        case 7: coordinate += "7";
                break;
    
    }
    
    return coordinate;
    
}
std::string GameTree::miniMaxDecision(){
/***************************************************************************//**
 * This function is an implementation of the minimax algorithm's   
 * minimaxDecision function. The function looks at the available legal moves
 * and searches all the subtrees branching off from each move and identifies
 * the sequence with the highest utility. All the sequences returned are then 
 * compared against each other and the one with the highest utility represents
 * the best move from that position.   
 ******************************************************************************/    

    Node *nodePtr = root;    // Pointer to a node
    int current = 0,max = 0; // Variables to record the max score
    std::string coords;  // Variable to store the coordinates of the chosen move
    
    // Run through the nodes array of pointers to child nodes
    for(int i=0;i<nodePtr->numChildren;i++){
        // Score the utility of the current node in the array
        current = miniMaxValue(nodePtr->children[i],nodePtr->children[i]->current->score,5);
        
        //If this value is higher then the current max, make it the new max 
        if(current>max){
            max = current;
            coords = nodePtr->children[i]->current->coordS + nodePtr->children[i]->current->coordM; 
        }
    }
    
    return coords;
    
}
int GameTree::miniMaxValue(Node* nodePtr,int total,int depth){
/***************************************************************************//**
 * This function is an implementation of the minimax algorithm's minimaxValue  
 * function. This function searches a node's array of child nodes looking for 
 * the one with the highest utility. This score is then added to the total and
 * that child node is recursively passed into this function and the function
 * continues until either the maximum depth is reached or the branch ends.  
 ******************************************************************************/
    
    // If the bottom has not been reached and there are legal moves available
    if(depth>1&&nodePtr->numChildren>0){
        
        // Find the child node with the highest utility
        int max = 0, index = 0;
        for(int i=0;i<nodePtr->numChildren;i++){
            if((nodePtr->children[i]->current->score)>=max){
                max = nodePtr->children[i]->current->score;
                index = i;
            }
        }
        // Add the max score to total and recursively pass in the node it's from
        total += max;
        return miniMaxValue(nodePtr->children[index],total,depth-1);
    }
    // Otherwise return the total of the max 
    else{
        return total;
    }
    
}