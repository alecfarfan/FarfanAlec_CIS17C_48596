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

    // Declared linked lists
    LinkedList<int> list;
    LinkedList<int> list2;
    
    //Append 1, 2, and 3 to the empty list
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    cout<<"Original: "<<list.toString()<<endl;
    cout<<"First: "<<list.first()<<endl;
    cout<<"Last: "<<list.last()<<endl;
    
    cout<<"List after prepending 7 then 15, appending 12 and prepending 9"<<endl;
    list.prepend(7);
    list.prepend(15);
    list.append(12);
    list.prepend(9);
    cout<<list.toString()<<endl;
    
    cout<<"List after inserting 25 after the 3rd index"<<endl;
    list.insertAfter(25,3);
    cout<<list.toString()<<endl;
    
    cout<<"List after inserting 21 before the 5th index"<<endl; 
    list.insertBefore(21,5);
    cout<<list.toString()<<endl;
  
    cout<<"List 2 with the first lists contents and a 5 appended"<<endl;
    list2 = list;
    list2.append(5);   
    cout<<list2.toString()<<endl;
    
    
    // End of program
    return 0;

}