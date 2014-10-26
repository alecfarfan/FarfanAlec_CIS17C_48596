/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a sorted linked list class
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Sorted_Linked_List.h"

// No global variables or constants

// Function prototypes

// Execution begins here
int main(int argc, char** argv) {

    srand(static_cast<int>(time(0)));
    Sorted_Linked_List<int> list;
    
    for(int i=0;i<50;i++){
        list.insert(rand()%90+10);
    }
    
    cout<<"A sorted linked list with 50 random numbers inserted "<<endl;
    list.print();
    
    // End of program
    return 0;

}