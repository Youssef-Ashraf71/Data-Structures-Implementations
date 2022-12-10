#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
template <class T>
struct Node{
    T data;
    Node *next,*prev;
  Node(T data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
};
#endif