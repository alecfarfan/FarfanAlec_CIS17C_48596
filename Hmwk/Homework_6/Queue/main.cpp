/* 
 * Name: Alec Farfan
 * Date: 05/08/14
 * Purpose: Implement a Queue class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Queue.h"

// No global variables or constants

// Function prototypes

// Execution begins here
int main(int argc, char** argv) {

    Queue<int> queue;
    
    for(int i=0;i<50;i++){
        queue.enqueue(i);
    }
    
    cout<<"A queue filled with numbers 1 - 49 printed to the screen in "<<endl;
    cout<<"order by dequeueing each element one by one"<<endl;
    for(int i=0;i<50;i++){
        int dummy;
        queue.dequeue(dummy);
        cout<<dummy<<" ";
        
        if(i%10==9){
            cout<<endl;
        }
    }
    
    // End of program
    return 0;

}