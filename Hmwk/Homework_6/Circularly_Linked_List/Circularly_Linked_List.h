/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a circularly linked list class
 */

#ifndef CIRCULARLY_LINKED_LIST_H
#define	CIRCULARLY_LINKED_LIST_H

template <class T>
class Circularly_Linked_List{
    

    private:
        struct Node{
            T value;
            Node *next;
        };
        Node *head;
        Node *tail;
        
    public:
        Circularly_Linked_List();        
        ~Circularly_Linked_List();
        void append(T);
        void prepend(T);
        T first();
        T last();
        void print();
    
};
template <class T>
Circularly_Linked_List<T>::Circularly_Linked_List(){
    
    head = NULL;
    tail = NULL;
    
}
template <class T>
Circularly_Linked_List<T>::~Circularly_Linked_List(){
    
    Node *transPtr = head;
    Node *nextNode;
    
    do{
        nextNode = transPtr->next;
        delete transPtr;
        transPtr = nextNode;   
        
    }while(transPtr!=head);
        
    
}
template <class T>
void Circularly_Linked_List<T>::append(T val){
    
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;
    
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    
}
template <class T>
void Circularly_Linked_List<T>::prepend(T val){
    
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;
    
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    
}
template <class T>
T Circularly_Linked_List<T>::first(){
    
    return head->value;
    
}
template <class T>
T Circularly_Linked_List<T>::last(){
    
    return tail->value;
    
}
template <class T>
void Circularly_Linked_List<T>::print(){
    
    Node *transPtr;
    int i = 0;
    
    if(head){
        transPtr = head;
        do{
            std::cout<<transPtr->value<<" ";
            if(i % 10 == 9){
                std::cout<<std::endl;
            }
            transPtr = transPtr->next;
            i++;
        }while(transPtr!=head);
           
        }
    
    std::cout<<std::endl;
    
}
#endif	/* CIRCULARLY_LINKED_LIST_H */