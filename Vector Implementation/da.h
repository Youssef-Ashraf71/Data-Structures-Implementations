#ifndef __DA_H__
#define __DA_H__
#include<iostream>
using namespace std;

template<class T >class My_DA{
private:
    int size = 0;
    int capacity = 1;
    int* data = nullptr;
public:
    // Default constructor
    My_DA();
    // Constructor that takes an array and its size so it is added directly to data
    My_DA(T arr[], int sz);
      ~My_DA();
    // return the element at given index
    T get(int index);
    void push(T  element);
    // remove the last element, return the removed element
    int pop();
    // insert an element at certain index
    void insert(int index, T element);
    // remove the element at a given index, return the removed element
    T remove(int index);
    // print the whole array
    void print();
    // clear the whole array
    void clear();
    // given an element, return the first index of the given element if found, return -1 if not found
    int find(T element);
    // return size of arr
    int get_size();
    // return capacity of arr
    int get_capacity();
    // shrink the capacity of arr to size
    void shrinktofit();
    // function to resize the array to avoid writing same code block more than one time
    void recreate( int new_capacity);
};

#endif