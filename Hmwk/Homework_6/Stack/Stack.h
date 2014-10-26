/* 
 * Name: Alec Farfan
 * Date: 05/31/14
 * Purpose: Implement a Stack class
 */

#ifndef STACK_H
#define	STACK_H

template <class T>
class Stack{
    
    private:
        struct Node{
            T value;
            Node* next;
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
    
    Node *transPtr = top;
    Node *nextNode;
    
    while(transPtr){
        nextNode = transPtr->next;
        delete transPtr;
        transPtr = nextNode;
    }
    
}
template <class T>
bool Stack<T>::isEmpty(){
    
    if(top){
        return false;
    }
    else{
        return true;
    }
    
}
template <class T>
void Stack<T>::push(T val){
    
    Node *transPtr;
    Node *newNode = new Node;
    newNode->value = val;
    
    if(isEmpty()){
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
    
    if(isEmpty()){
        cout<<"Error: Stack is empty"<<endl;
    }
    else{
        val = top->value;
        Node *transPtr = top->next;
        delete top;
        top = transPtr;
    }
    
}
#endif	/* STACK_H */