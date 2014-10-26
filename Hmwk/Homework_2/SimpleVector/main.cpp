/* 
 * Name: Alec Farfan
 * Date: 
 * Purpose: Gaddis 7th Edition Chapter Problem ()
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "SimpleVector.h"

// No global variables or constants

// Function prototypes
void doAgain(char&);

// Execution begins here
int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    // Declare repeat variable
    char repeat;
    do{
        // Declare variables
        SimpleVector<int> tester(50);
        int pullTest = 0;
        
        tester.fill();
        cout<<"Original array"<<endl;
        tester.print();
        
        tester.push(99);
        cout<<"Array with new number pushed at the end"<<endl;
        tester.print();
       
        tester.pull(pullTest);
        cout<<"The last element in the array is: "<<pullTest<<endl<<endl;
        cout<<"Array with last element removed"<<endl;
        tester.print();
        
        // Ask user if they would like to repeat the program
        doAgain(repeat);
    }while(toupper(repeat)=='Y');
    
    // End of program
    return 0;

}
void doAgain(char& repeat){

    cout<<"Would you like to repeat the program? Enter"<<endl;
    cout<<"Y to repeat or enter anything else to exit:";
    cin>>repeat;
    
    cin.ignore();
    system("CLS");    

}