/*
       ____            ___________
      /\   \          |
     /  \   \         |
    /    \   \        |___________
   /______\   \                  |
  /        \   \                 |
 /          \  /       __________|
/            \/

 ___  ___              F
|\  \|\   \            F
\ \  \_\   \           F
 \ \ ___    \          F
  \  \ \\ \  \         F
   \  \__\\ \_\        F
    \ |__| \|__|       F

 */
#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
using namespace std;

struct Node{
    int data;
    Node * next;
};
// Stack Implementation Using Single Linked List
class Stack{
private:
    Node* Top=NULL; // points to the first element in stack
    Node* Iterator=NULL;  // points to iterate the stack
    int size=0;
public:
    // function to insert an element at the end of the stack
    void push(int value ){
        Node* new_node=new Node;
        new_node->data=value;
        new_node->next=Top;
        Top=new_node; size++;
    }
// function to display the data stored in the stack
    void print(){
        Iterator=Top;
        cout<<"Size: "<<size<<endl;
        while (Iterator!=NULL){
            cout<<Iterator->data<<" "; Iterator=Iterator->next;
        }
        cout<<endl;
    }
    // function to remove certain element from the stack
    void pop(){
        if(Top==NULL) { cout<<"Empty stack"<<endl; return; }
        Iterator=Top;
        Top=Top->next;
        free(Iterator);  size--;
    }
    // function to return the element at the top of the stack
    int top(){
        if(Top!=NULL) return Top->data;
        cout<<"Stack Underflow"<<endl; return -1;
    }



};

int main()
{
    fast; // ashf gamed tenen




    return 0;
}