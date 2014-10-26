/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a priority queue class
 */

#ifndef PRIORITY_QUEUE_H
#define	PRIORITY_QUEUE_H

#include "LinkedList.h"

template <class T>
class Priority_Queue: public LinkedList<T> {
    
    private:
        struct Node{
            T value;
            Node *next;
        };
    public:
         Priority_Queue();
         void extractMin(T&);   

};
template <class T>
Priority_Queue<T>::Priority_Queue(): LinkedList<T>::LinkedList(){
    
}
template <class T>
void Priority_Queue<T>::extractMin(T& val){

    T min;
    int index = 0;
    
    if(this->head){
        this->transPtr = this->head;
        int pos = 0;
        min = this->transPtr->value;
        
        while(this->transPtr){
            if(this->transPtr->value<min){
                min= this->transPtr->value;
                index = pos;
            }
            this->transPtr = this->transPtr->next;
            pos++;
        }
    }

    val = min;
    this->delNode(min);
    
}
#endif	/* PRIORITY_QUEUE_H */