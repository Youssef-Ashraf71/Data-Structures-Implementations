#ifndef __Deque_H__
#define __Deque_H__
#include <iostream>
#include <vector>
#include "node.h"
template <class T>
class My_Deque{
    private:
        int size;
        Node<T>* front;
        Node<T>* rear;
        bool isempty(){
            if(size==0 || front==NULL) return 1;
            return 0;
        }
    public:
    // Constructor for initializing the deque
        My_Deque();
    // Destructor for Destroying the deque
        ~My_Deque();
        //to return the last element in the deque
        T end();

        //to return the first element in the deque
        T begin();
        
        // add the element to the end of the deque
        void push_back(T element);

        // add the element to the beginning of the deque
        void push_front(T element);
        
        // remove the last element, return the removed element
        T pop_back();

        // remove the first element, return the removed element
        T pop_front();

        // convert the deque to vector and return that vector
        std::vector<T> toVector();
        
        // print the whole deque from head to tail
        void print();

        // clear the whole deque
        void clear();

        // return the deque size
        int get_size();
        
};
#include "deque.tpp" // to link the implementation with the declarations
#endif