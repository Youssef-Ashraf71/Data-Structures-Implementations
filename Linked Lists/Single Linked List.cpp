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
  /*  Node(int input,Node* newele=NULL){
        data=input; next=newele;
    }*/
};
class LinkedList{
private:
Node* head=NULL; // points to the first element in list
Node* cur=NULL;  // points to the last node in list
int size=0;
public:
   /* LinkedList(){

    }*/
   // function to insert an element at the end of the list
    void insert(int value ){
      Node* new_node=new Node;
      new_node->data=value;
      if(head==NULL){
          head=new_node;  new_node->next=NULL;   // first node
      }
      else {
          // insert at the end of the list
          cur=head;
          while(cur->next!=NULL) cur=cur->next;
          cur->next = new_node;
          new_node->next=NULL;
      }
      size++;
    }
// function to display the data stored in the list
    void print(){
        Node* iterator=head;
        cout<<"Size: "<<size<<endl;
        if(!size) return;
        while (iterator!= nullptr){
            cout<<iterator->data<<" ";
            iterator=iterator->next;
        }
        cout<<endl;
    }
    // function to remove certain element from the list
    void remove(int element ){
     Node*prev;
     prev= nullptr; cur=head;
     if(cur->data==element) {  head=cur->next; free(cur); size--; return;  } // if element to be removed is the head
     while (cur->data!=element){
         prev=cur; cur=cur->next;
     }
     if(cur->next== nullptr && cur->data!=element){  cout<<"Not found\n"; return; } // if element is not found in the list
     prev->next=cur->next; free(cur); size--;
    }
    // function to add to the front of the list
    void push_front(int element){
        Node* new_node=new Node;
        new_node->data=element;
        new_node->next=head;
        head= new_node; size++;
    }
    // function to remove last element from the list
    void pop_back(){
        if(head== nullptr){ cout<<"Empty List\n"; return; }
        if(head->next==NULL){ delete (head); head=NULL; size--; return;  }
        Node* prev=NULL; cur=head;
        while (cur->next!= NULL){
            prev=cur; cur=cur->next;
        }
       prev->next= NULL;  free(cur); size--;
    }
    // function to remove front element from the list
    void pop_front(){
        if(head== nullptr){ cout<<"Empty List\n"; return; }
        cur=head;
        head=cur->next;
        delete (cur); size--;
    }

};
int main()
{
    fast; // ashf gamed tenen



    return 0;
}