/* 
 * Name: Alec Farfan
 * Date: 05/08/14
 * Purpose: Implement a linked list class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "LinkedList.h"

// No global variables or constants

// Function prototypes
void doAgain(char&);

// Execution begins here
int main(int argc, char** argv) {

    srand(static_cast<int>(time(NULL)));   
    
    // Declare repeat variable
    //Create a linked list
    LinkedList<int> list;
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    
    // End of program
    return 0;

}