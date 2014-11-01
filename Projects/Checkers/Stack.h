/* 
 * File:   Stack.h
 * Author: Alec
 *
 * Created on June 5, 2014, 4:03 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>

template <class T>
class Stack{
    
    private:
        
        struct Node{
            T value;
            Node *next;
        };
        
        Node *top;
        
    public:
        
        Stack();
        ~Stack();
        bool isEmpty();
        void push(T);
        void pop(T&);
        
};
template <class T>
Stack<T>::Stack(){
    
    top = NULL;
    
}
template <class T>
Stack<T>::~Stack(){
    
    Node *nodePtr = top;
    Node *nextNode;
    
    while(nodePtr==NULL){
        nextNode->next = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    
}
template <class T>
bool Stack<T>::isEmpty(){
    
    if(top){
        return false;}
    else{
        return true;}
    
}
template <class T>
void Stack<T>::push(T val){
    
    Node *newNode = new Node;
    newNode->value = val;
    
    if(!top){
        top = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    
}
template <class T>
void Stack<T>::pop(T& val){
    
    Node *temp;
    
    if(!top){
        std::cout<<"Error. The Stack is empty"<<std::endl;
    }
    else{
        val = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    
}
#endif	/* STACK_H */