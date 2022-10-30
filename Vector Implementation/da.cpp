#include "da.h"
#include <iostream>
using namespace std;
// implement all the methods in da.h
// feel free to add new helper methods whether private or public

// Default constructor
template<class T> My_DA<T>::My_DA(){
    size=0; capacity=1;
    data = new T[capacity];
}
// Constructor that takes an array and its size so it is added directly to data
template<class T> My_DA<T>::My_DA(T arr[], int sz){
    size=0; capacity=1;
    // calculating the capacity
    for(int i=0;i<sz;i++){
        size++;
        if(size>=capacity) capacity*=2;
    }
    data=new T[capacity];
    for(int i=0;i<sz;i++){
        data[i]=arr[i];
    }
}
// Destructor
template<class T> My_DA<T>::~My_DA() {
    if(data!= nullptr) delete []data;
}

// return the element at given index
 template<class T> T My_DA<T>:: get(int index){
    if(index<size) return data[index];
    return -1;
}
// push new element
template<class T> void  My_DA<T>::push(T element){
    if(size==capacity){
        // if full expand the array
        capacity*=2;  recreate(capacity); // resize the array
    }
    data[size]=element; size++;
}

template<class T> int My_DA<T>::pop() {
    T element=data[size-1];
    if(!size){  return -1; } // cant do pop bec vector is empty
    size--;
    if(size<capacity/2){
        capacity/=2; recreate(capacity); // resize the array
    }
    return element;
}

template<class T> void My_DA<T>::insert(int index, T element) {
    if(size==capacity)
    {
        capacity*=2;
    }
    // shift all data after index right shift by 1
    T * newarr=new T [capacity];
    for(int i=0;i<index;i++){
        newarr[i]=data[i];
    }
    newarr[index]=element;
    for(int i=index;i<size;i++){
        newarr[i+1]=data[i];
    }
    size++;
    delete []data;
    data=newarr;
}
template<class T> T My_DA<T>::remove(int index) {
    if(index>=size) return -1;
    T element=data[index];
    // shift all elements after index to left by 1
    for(int i=index;i<size-1;i++){
        data[i]=data[i+1];
    }
    size--;
    if(size<capacity/2){
        capacity/=2; recreate(capacity);
    }
    return element;
}
template<class T> void My_DA<T>::print() {
   for(int i=0;i<size;i++){
       cout<<data[i]<<" ";
   }
   cout<<endl;
}
template <class T>void My_DA<T>::clear() {
    delete []data;
    // clearing the array and creating new one
    size=0; capacity=1;
    data = new T[capacity];
}
template<class T> int My_DA<T>::find(T element) {
    for(int i=0;i<size;i++){
        if(data[i]==element) return i; // if element found return index
    }
    return -1;
}

template<class T> int My_DA<T>::get_size() {
    return size;
}

template<class T> int My_DA<T>::get_capacity() {
    return capacity;
}

template<class T> void My_DA<T>::shrinktofit() {
    // shrinking capacity to size
    recreate(size);  capacity=size;
}
template<class T>
// function to resize the array
void My_DA<T>::recreate(int new_capacity) {
    T * newarr=new T[new_capacity];
    for(int i=0;i<size;i++){
        newarr[i]=data[i];
    }
    delete []data;
    data=newarr;
}

