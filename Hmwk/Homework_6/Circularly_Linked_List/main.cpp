/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a circularly linked list class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Circularly_Linked_List.h"

// No global variables or constants

// Function prototypes

// Execution begins here
int main(int argc, char** argv) {

    Circularly_Linked_List<int> test;
    for(int i=0;i<50;i++){
        test.append(i);
    }
    
    cout<<"Circularly linked list filled with numbers 0 - 49"<<endl;
    test.print();
    cout<<"Head: "<<test.first()<<endl;
    cout<<"Tail: "<<test.last()<<endl;
    
    cout<<"Same list with the number 23 prepended and 32 appended"<<endl;
    test.prepend(23);
    test.append(32);
    test.print();
    cout<<"Head: "<<test.first()<<endl;
    cout<<"Tail: "<<test.last()<<endl;
    
    // End of program
    return 0;

}