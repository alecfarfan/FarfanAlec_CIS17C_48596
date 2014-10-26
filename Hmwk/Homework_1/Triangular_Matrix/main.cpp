/* 
 * Name: Alec Farfan
 * Date: 09/08/14
 * Purpose: Test Triangular Matrix Template
 */

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Include header files
#include "Triangular_Matrix.h"

// No global variables

// Functions prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    // Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Declare variables for row, column, and lines per row 
    int rows=5,cols=10;
    int cls=rows,perLine=10;
    
    // Declare integer triangular matrixes of each type
    TriangularMatrix<int> intMatrix1(cls);
    TriangularMatrix<int> intMatrix2(rows,cols);
    TriangularMatrix<int> intMatrix3(rows,intMatrix1.getColAry());
    
    // Declare float triangular matrixes of each type
    TriangularMatrix<float> floatMatrix1(cls);
    TriangularMatrix<float> floatMatrix2(rows,cols);
    TriangularMatrix<float> floatMatrix3(rows,floatMatrix1.getColAry());
    
    //Print the arrays
    intMatrix1.printArray(rows,cols);
    intMatrix2.printArray(cls,rows,cols);
    intMatrix3.printArray(rows,intMatrix3.getColAry());
    floatMatrix1.printArray(rows,cols);
    floatMatrix2.printArray(cls,rows,cols);
    floatMatrix3.printArray(rows,floatMatrix3.getColAry());
    
    //Delete the arrays
    intMatrix1.destroy();
    intMatrix2.destroy(rows);
    intMatrix3.destroy(rows);
    floatMatrix1.destroy();
    floatMatrix2.destroy(rows);
    floatMatrix3.destroy(rows);
    
    //Exit stage right
    return 0;
    
}