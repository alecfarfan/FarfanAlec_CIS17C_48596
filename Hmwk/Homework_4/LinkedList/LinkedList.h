/*! 
 * \class LinkedList "LinkedList.h"
 * This class is an implementation of a singly linked list. The class contains a
 * constructor, destructor, copy constructor, as well as functions providing 
 * facilities to append, insert, and delete nodes. The class contains a function
 * for printing the list to the console as well.
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

// Include libraries
#include <cstdlib>
#include <sstream>

template <class T>
class LinkedList{
    
    private:
        
        struct Node{    
            T value;
            struct Node *next;
        };
        Node *head;
        
    public:
        
        LinkedList(){ head = NULL;}
        LinkedList(const LinkedList&);
        ~LinkedList();
        void append(T);
        void insert(T);
        void delNode(T);
        void print()const;
        string toString();
        
};
template <class T>
LinkedList<T>::LinkedList(const LinkedList& obj){
/***************************************************************************//**
 * This function is a copy constructor for the LinkedList class. 
 ******************************************************************************/    
    
    // If the list to be copied is empty, set the head to null
    if(obj.head==NULL){
        head = NULL;
    }
    // Otherwise create a new list of nodes and copy the data into them
    else{
        head = new Node;                // Allocate a new node for head
        head->value = obj.head->value;  // Set heads value to the objects value
        Node *nodePtr = head;           // Pointer to this list
        Node *objPtr = obj.head->next;  // Pointer to the list to be copied
        // Copy the entire list 
        while(objPtr){
            nodePtr->next = new Node;       // Allocate a node to be put next
            nodePtr = nodePtr->next;        // Skip to the new node
            nodePtr->value = objPtr->value; // Then copy the data into it
            objPtr = objPtr->next;          // Go to the next node in the list
        }
        nodePtr->next = NULL; // Point the last node of the list to null
    }
    
}
template <class T>
LinkedList<T>::~LinkedList(){
    
    Node *transPtr;
    Node *nextNode;
    
    transPtr = head;
    
    while(transPtr!=NULL){
        nextNode = transPtr->next;
        delete transPtr;
        transPtr = nextNode;
    }
    
}
template <class T>
void LinkedList<T>::append(T val){
/***************************************************************************//**
 * This function provides the functionality for appending a new Node structure
 * to the end of a Linked List object. 
 ******************************************************************************/
    
    Node *newNode = new Node;  // Node structure to be appended
    Node *transPtr;            // Node pointer to transverse the list
    
    newNode->value = val;      // Set the value field to the argument passed in
    newNode->next = NULL;      // Make the next field point to NULL
    
    if(!head){                 // If there's not yet any nodes in the list, make
        head = newNode;        // the new node the head.
    }
    else{                      // Otherwise we will append the new node to end
        transPtr = head;       // Make the trans pointer point to the beginning
        
        while(transPtr->next){ // Transverse the list until the end is found
            transPtr = transPtr->next;
        }
        transPtr->next = newNode;      // Append the new node!
    }
    
}
template <class T>
void LinkedList<T>::insert(T val){
/***************************************************************************//**
 * This function provides the functionality for inserting a new Node structure
 * anywhere within a Linked List object. 
 ******************************************************************************/
 
    Node *newNode = new Node; // Node structure to be inserted
    Node *transPtr;           // Node pointer to transverse the list
    Node *trailPtr = NULL;    // Node pointer to trail the transversing pointer
    
    newNode->value = val;     // Set the value field to the argument passed in
                              
    if(!head){                // If there's not yet any nodes in the list, make
        head = newNode;       // the new node the head.
        newNode->next = NULL; // Make the new node point to NULL
    }
    else{                     // Otherwise...
        transPtr = head;      // Set the transversing node equal to the head and
        trailPtr = NULL;      // the previous node to null.
        
        while(transPtr!=NULL && transPtr->value<val){ // Transverse the list 
            trailPtr = transPtr;            // until a greater value is found or
            transPtr = transPtr->next;      // the end of the list is reached.
        }
        if(trailPtr==NULL){       // If the trail pointer is still pointing to
            head = newNode;       // null, set the new node as the head and make 
            newNode->next = transPtr; // it point to the transverse pointer.
        }
        else{                          // Otherwise make the trailing pointer 
            trailPtr->next = newNode;  // point to the new node, and make the
            newNode->next = transPtr;  // new node point to the transverse.
        }   
    }

}

template <class T>
void LinkedList<T>::delNode(T val){
    
    Node *trailPtr;
    Node *transPtr;
    
    if(!head){
        return;
    }
    if(head->value==val){
        transPtr = head->next;
        delete head;
        head = transPtr;
    }
    else{
        transPtr = head;
        while(transPtr!=NULL&&transPtr->value!=val){
            trailPtr = transPtr;
            transPtr = transPtr->next;
        }
        if(transPtr){
            trailPtr->next = transPtr->next;
            delete transPtr;
        }
    }
    
}
template <class T>
void LinkedList<T>::print()const{
/***************************************************************************//**
 * This function provides the functionality for transversing a Linked List
 * object and printing its contents at each node.
 ******************************************************************************/    

    Node *transPtr = head; // Pointer to transverse the list
    int i = 0;             // Variable to keep track of number of outputs
    
    // Transverse the list and print each element to the screen
    while(transPtr){
        cout<<transPtr->value<<" ";  
        transPtr = transPtr->next;
        
        if(i%10==9){      // Print and end-line after each 10 elements
            cout<<endl;
        }
        i++;
    }
    cout<<endl;
    
}
template <class T>
string LinkedList<T>::toString(){
    
    Node *transPtr = head;
    stringstream foo;
    
    if(head){
        while(transPtr){
             foo<<transPtr->value<<" ";           
            transPtr = transPtr->next;
        }
    }
    
    return foo.str();
}

#endif	/* LINKEDLIST_H */