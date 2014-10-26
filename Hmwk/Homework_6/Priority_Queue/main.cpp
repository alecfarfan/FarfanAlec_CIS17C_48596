/* 
 * Name: Alec Farfan
 * Date: 05/08/14
 * Purpose: Implement a priority queue class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Priority_Queue.h"

// No global variables or constants

// Function prototypes

// Execution begins here
int main(int argc, char** argv) {

    srand(static_cast<int>(time(0)));
    
    Priority_Queue<int> test;
    for(int i=0;i<50;i++){
        test.prepend(rand()%90+10);
    }
    cout<<"Original set of numbers stored in priority queue"<<endl;
    test.print();
    
    int dummy;
    
    test.extractMin(dummy);
    cout<<"Highest priority element '"<<dummy<<"' was deleted"<<endl;
    test.print();
    
    // End of program
    return 0;

}