/* 
 * Name: Alec Farfan
 * Date: 09/08/14
 * Purpose: Triangular Matrix Template
 */

#ifndef TRIANGULAR_MATRIX_H
#define	TRIANGULAR_MATRIX_H

// Include libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

template <class T>
class TriangularMatrix{
    
    private:
    
        T* array;
        T** array2;
        
    public:
        
        TriangularMatrix(int);
        TriangularMatrix(int,int);
        TriangularMatrix(int,T*);
        T*  fillArray(int);
        T** fillArray(int,int);
        T** fillArray(int,T*);
        T* getColAry();
        void printArray(int,int);
        void printArray(int,int,int);
        void printArray(int,T*);
        void destroy();
        void destroy(int);

};
template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows){
    
    array = fillArray(rows);
    
}
template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows,int cols){
    
    array2 = fillArray(rows,cols);
    
}
template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows, T* colAry){
    
    array = fillArray(rows);
    array2 = fillArray(rows,array);
    
}
template <class T>
T* TriangularMatrix<T>::fillArray(int cols){
    
    //Declare the 1-D Array
    T* array=new T[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
    
}

template <class T>
T** TriangularMatrix<T>::fillArray(int rows,int cols){
    
    //Declare the 2-D Array
    T** array=new T*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new T[cols];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]= rand()%90+10;
        }
    }
    return array;
    
}

template <class T>
T** TriangularMatrix<T>::fillArray(int rows,T* colAry){
    
    //Declare the 2-D Array
    T** array = new T*[rows];
    for(int row=0;row<rows;row++){
        //cout<<"Number of Cols = "<<colAry[row]<<endl;
        array[row]=new T[static_cast<int>(colAry[row])];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            array[row][col]=rand()%90+10;
            //cout<<"Row Col"<<row<<" "<<col<<endl;
        }
    }
    return array;
    
}

template <class T>
T* TriangularMatrix<T>::getColAry(){
    
    return array;
    
}
template <class T>
void TriangularMatrix<T>::printArray(int cols, int perLine){
    
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<array[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl; 
    }
    cout<<endl;
    
}

template <class T>
void TriangularMatrix<T>::printArray(int dummy, int rows, int cols){
    
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array2[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

template <class T>
void TriangularMatrix<T>::printArray(int rows, T* colAry){
   
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<<array2[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

template <class T>
void TriangularMatrix<T>::destroy(){
    
    //Destroy row pointers
    delete []array;

}

template <class T>
void TriangularMatrix<T>::destroy(int rows){
    
    //Destroy columns
    for(int row=0;row<rows;row++){
        delete []array2[row];
    }
    //Destroy row pointers
    delete []array2;
    
}

#endif	/* TRIANGULAR_MATRIX_H */