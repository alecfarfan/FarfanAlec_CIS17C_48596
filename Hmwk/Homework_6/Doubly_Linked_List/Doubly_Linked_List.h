/* 
 * Name: Alec Farfan
 * Date: 10/25/14
 * Purpose: Implement a doubly linked list class
 */

#ifndef DOUBLY_LINKED_LIST_H
#define	DOUBLY_LINKED_LIST_H

template <class T>
class Doubly_Linked_List{
    
    private:
        struct Node{
            T value;
            Node *next;
            Node *prev;
        };
        Node *head;
        Node *tail;
        int size;
        
    public:
        Doubly_Linked_List();
        ~Doubly_Linked_List();
        void append(T);
        void prepend(T);
        T first();
        T last();
        void print();
        void printReverse();
        
};
template <class T>
Doubly_Linked_List<T>::Doubly_Linked_List(){
    
    size = 0;
    head = NULL;
    tail = NULL;
    
}
template <class T>
Doubly_Linked_List<T>::~Doubly_Linked_List(){
    
    Node *transPtr;
    Node *nextNode;
    
    if(head){
        transPtr = head;
        while(transPtr){
            nextNode = transPtr->next;
            delete transPtr;
            transPtr = nextNode;
        }
    }
    
    
}
template <class T>
void Doubly_Linked_List<T>::append(T val){
    
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(size == 0){
        head = newNode;
        tail = newNode;
        size = 1;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    
}
template <class T>
void Doubly_Linked_List<T>::prepend(T val){
    
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(size == 0){
        head = newNode;
        tail = newNode;
        size = 1;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        size++;
    }
    
}
template <class T>
T Doubly_Linked_List<T>::first(){
    
    return head->value;
    
}
template <class T>
T Doubly_Linked_List<T>::last(){
    
    return tail->value;
    
}
template <class T>
void Doubly_Linked_List<T>::print(){
    
    Node* transPtr;
    int i = 0;
    
    if(size > 0){
        transPtr = head;
        while(transPtr){
            std::cout<<transPtr->value<<" ";
            transPtr = transPtr->next;
            
            if(i % 10 == 9){
                std::cout<<std::endl;
            }
            i++;
        }
    }
    std::cout<<std::endl;
    
}
template <class T>
void Doubly_Linked_List<T>::printReverse(){
   
    Node* transPtr;
    int i = 0;
    
    if(size > 0){
        transPtr = tail;
        while(transPtr){
            std::cout<<transPtr->value<<" ";
            transPtr = transPtr->prev;
            
            if(i % 10 == 9){
                std::cout<<std::endl;
            }
            i++;
        }
    }
    std::cout<<std::endl;

}
#endif	/* DOUBLY_LINKED_LIST_H */