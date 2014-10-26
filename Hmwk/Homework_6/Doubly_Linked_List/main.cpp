/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a doubly linked list class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Doubly_Linked_List.h"

// No global variables or constants

// Function prototypes

// Execution begins here
int main(int argc, char** argv) {

    Doubly_Linked_List<int> test;
    for(int i=0;i<50;i++){
        test.append(i);
    }
    
    cout<<"Doubly linked list printed by traversing the list forwards"<<endl;
    test.print();
    
    cout<<"Same list printed out in reverse by traversing backwards"<<endl;
    test.printReverse();
    
    cout<<"Head: "<<test.first()<<endl;
    cout<<"Tail: "<<test.last()<<endl;
    
    cout<<"List with new elements prepended"<<endl;
    test.prepend(14);
    test.prepend(37);
    test.print();
    
    // End of program
    return 0;

}