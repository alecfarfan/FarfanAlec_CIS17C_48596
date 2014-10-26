/* 
 * Name: Alec Farfan
 * Date: 05/08/14
 * Purpose: Implement a Stack class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Stack.h"

// No global variables or constants

// Function prototypes
void doAgain(char&);

// Execution begins here
int main(int argc, char** argv) {

    Stack<int> stack;
    for(int i=0;i<50;i++){
        stack.push(i);
    }
    
    cout<<"Stack filled with numbers 0 - 49 and then printed out in reverse"<<endl;
    cout<<"by popping elements off the top of the stack"<<endl;\

    for(int i=0;i<50;i++){
        int dummy;
        stack.pop(dummy);
        cout<<dummy<<" ";
        
        if(i%10==9){
            cout<<endl;
        }
        
    }
    
    // End of program
    return 0;

}