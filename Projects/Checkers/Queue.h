/***************************************************************************//**
 * \class Queue Queue.h "Queue.h" 
 * The Queue class is an implementation of a queue data structure. A queue 
 * stores and retrieves its elements in a first in first out manner (FIFO). This
 * implementation is dynamic, so the size of the data structure may fluctuate 
 * during the program if necessary.                                        
 ******************************************************************************/

#ifndef QUEUE_H
#define	QUEUE_H

#include <cstdlib>
#include <iostream>

template <class T>
class Queue{
    
    private:
        
        struct Node{
            T value;
            Node *next;
        };
        
        Node *front,
             *rear;
        int size;
        
    public:
        
        Queue();
        ~Queue();
        int getSize(){return size;}
        void clear();
        bool isEmpty();
        void enqueue(T);
        void dequeue(T&);
        
};
template <class T>
Queue<T>::Queue(){
/***************************************************************************//**
 * This function is the constructor for the Queue class. The function  
 * automatically sets the front and rear pointers to null, then sets the size
 * data member to zero.
 ******************************************************************************/
    
    // Set the front and rear pointers to null
    front = NULL;
    rear = NULL;
    
    // Set the size to zero
    size = 0;
    
}
template <class T>
Queue<T>::~Queue(){
/***************************************************************************//**
 * This function is the destructor for the Queue class. The function calls the  
 * clear function which will delete the contents of the container by popping out
 * all of the elements into a dummy variable
 ******************************************************************************/
    
    clear();
    
}
template <class T>
void Queue<T>::clear(){
/***************************************************************************//**
 * This function is used in a call from the destructor of this class in order  
 * to clear the contents of a queue. A dummy variable is declared to be used as
 * a parameter for the dequeue function which will pop each element out one at
 * a time until the container is empty 
 ******************************************************************************/
    
    // Declare a dummy variable to hold the elements being popped out
    T dummy;
    
    // Dequeue each element until the container is empty
    while(!isEmpty()){
        dequeue(dummy);
    }
        
}
template <class T>
bool Queue<T>::isEmpty(){
/***************************************************************************//**
 * This function is used to determine whether or not a queue is empty. This   
 * function is mainly used in the clear function but as well for error checking
 * in the pop function.
 ******************************************************************************/
    
    // If size is less than one then the container is empty, true is returned
    if(size<1){
        return true;
    }
    // Otherwise there are elements and the queue and the function returns false
    else{
        return false;
    }
    
}
template <class T>
void Queue<T>::enqueue(T val){
/***************************************************************************//**
 * This function is used to add elements into the queue. A new node is declared  
 * and the value passed into the function is set as the node's value attribute.
 * If the queue is empty then the current node becomes the front and rear. 
 * Otherwise the node is added to the rear of the queue container. Finally the
 * size is incremented to keep track of the number of elements.
 ******************************************************************************/
    
    // Allocate a new node and assign it the data passed into the function
    Node *newNode = new Node;
    newNode->value = val;
    
    // If the container is empty then make the current node the front and rear
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }
    // Otherwise attatch the new node to the rear of the container
    else{
        rear->next = newNode;
        rear = newNode;
    }
    
    // Increment the size to keep track of the number of elements in the queue
    size++;
    
}
template <class T>
void Queue<T>::dequeue(T& val){
/***************************************************************************//**
 * This function is used to dequeue the elements stored inside a queue container   
 * If the container is not empty, then the value of the front node is removed 
 * from the container and is assigned to the reference variable passed into the
 * function. Finally the size variable is decremented to reflect the changes in
 * the number of elements in the container. 
 ******************************************************************************/
    
    // Declare a pointer to a node
    Node *temp;
    
    // Verify that there are elements in the queue
    if(isEmpty()){
        std::cout<<"Error. The Queue is empty"<<std::endl;
    }
    // If there are elements in the queue get the front
    else{
        val = front->value;  // Assign the value of front's node to the argument 
        temp = front;        // Point the temp Pointer to the front
        front = front->next; // Make the next in the queue the new front
        delete temp;         // Delete the old front held by the temp pointer
        
        // Decrement the size member to reflect changes
        size--;
        
    }
    
}
#endif	/* QUEUE_H */