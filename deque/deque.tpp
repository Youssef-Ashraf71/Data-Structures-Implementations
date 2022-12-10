#include "deque.h"
#include <iostream>
using namespace std;

template<class T> My_Deque<T>::My_Deque(){
    front=NULL; rear=NULL; size=0;
}

template<class T> My_Deque<T>::~My_Deque() {
    Node<T>* current = front;
    // Destroying the deque
    while( current != NULL) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    front = NULL;
}

template<class T> T My_Deque<T>::end() {
    return (isempty()) ? -1:rear->data;
}

template<class T> T My_Deque<T>::begin() {
    return (isempty()) ? -1:front->data;
}

template<class T> void My_Deque<T>::push_back(T element) {
    // If deque is Empty create the node and  initialize front and rear with this node
    if(isempty()){
        Node<T>* new_node=new  Node<T>(element);
        front=rear=new_node;
    }
    // if not empty >> insert the node at the end of deque and join next/previous of the node with the Previous Node
    else{
        Node<T>* new_node=new  Node<T>(element);
        rear->next=new_node;
        new_node->prev=rear;
        rear=new_node;
    }
    size++;
}

template<class T> void My_Deque<T>::push_front(T element) {
    // If deque is Empty create the node and  initialize front and rear with this node
if(isempty()){
    Node<T>* new_node=new  Node<T>(element);
    front=rear=new_node;
}
// if not empty >> insert the node at the Front of deque and join next/previous of the node with the Next Node
else{
    Node<T>* new_node=new  Node<T>(element);
    new_node->next=front;
    front->prev=new_node;
    front=new_node;
}
size++;
}

template<class T> T My_Deque<T>::pop_back() {
    int removed;
    if(isempty()){
        return -1;
    }
    // if size =1
    else if(front->next==NULL){
        removed=rear->data;
        delete rear;
        front=rear=NULL;
    }
    // if size>1
    else{
        removed=rear->data;
        Node<T>* tmp=rear;
        rear=rear->prev; rear->next=NULL; delete tmp;
    }
    size--;
    return removed ;
}

template<class T> T My_Deque<T>::pop_front() {
    int removed;
    if(isempty()){
        return -1;
    }
    // if size =1
    else if(front->next==NULL){
        removed=front->data;
        delete front;
        front=rear=NULL;
    }
    // if size>1
    else{
        removed=front->data;
        Node<T>* tmp=front;
        front=front->next; front->prev=NULL;
        delete tmp;
    }
    size--;
    return removed;
}

template<class T> vector<T> My_Deque<T>::toVector() {
    // create a vector and iterate through the deque and push every element to the vector and return it
    vector<int>ret;
    Node<T>* iterator=front;
    while (iterator!=NULL){
        ret.push_back(iterator->data);
        iterator=iterator->next;
    }
    return ret;
}

template<class T> void My_Deque<T>::print() {
   if(isempty()){ cout<<"Empty "<<endl; return; }
   cout<<"Size :"<<size<<endl;
    Node<T>* iterator=front;
   while (iterator!=NULL){
       cout<<iterator->data<<" ";
       iterator=iterator->next;
   }
   cout<<endl;
}

template<class T> void My_Deque<T>::clear() {
    Node<T>* iterator=front;
    while (iterator!=NULL){
        Node<T>* tmp=iterator;
        iterator=iterator->next;
        delete tmp;
    }
    front=NULL; rear=NULL; size=0;
}

template<class T> int My_Deque<T>::get_size() {
    return size;
}

