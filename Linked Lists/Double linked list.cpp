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
    Node * Prev;
  /*  Node(int input,Node* newele=NULL){
        data=input; next=newele;
    }*/
};
class LinkedList{
private:
Node* head=NULL; // points to the first element in list
Node* cur=NULL;  // points to the last node in list
Node* Tail=NULL;
int size=0;
public:
   /* LinkedList(){

    }*/
   // function to insert an element at the end of the list
    void insert(int value ){
      Node* new_node=new Node;
      new_node->data=value;
      if(head==NULL){
          head=new_node;  new_node->next=NULL;  new_node->Prev=NULL;    // first node
      }
      else {
          // insert at the end of the list
          cur=head;
          while(cur->next!=NULL) cur=cur->next;
          cur->next = new_node;
          new_node->next=NULL;    new_node->Prev=cur;
      }
       Tail=new_node;  size++;
    }
// function to display the data stored in the list
    void print(){
        Node* iterator=head;
        cout<<"Size: "<<size<<endl;
        if(!size) return;
        while (iterator->next!= nullptr){
            cout<<iterator->data<<" ";
            iterator=iterator->next;
        }
        cout<<iterator->data<<" ";
        cout<<endl;
    }
    // function to remove certain element from the list
    void remove(int element ){
     Node*prev;
     prev= nullptr; cur=head;
     if(head==NULL){ cout<<"Empty List"<<endl; return; }
     if(cur->data==element) {  head=cur->next; cur->next->Prev=NULL; free(cur); size--; return;  } // if element to be removed is the head
     while (cur->data!=element){
         prev=cur; cur=cur->next;
     }
     if(cur->next== nullptr && cur->data!=element){  cout<<"Not found\n"; return; } // if element is not found in the list
     prev->next=cur->next; cur->next->Prev=prev; free(cur); size--;
    }
    // function to add to the front of the list
    void push_front(int element){
        Node* new_node=new Node;
        new_node->data=element;
        new_node->next=head;
        new_node->next->Prev=new_node;
        head= new_node; new_node->Prev=NULL; size++;
    }
    // function to remove last element from the list
    void pop_back(){
        if(size==0 || head==NULL){ cout<<"Empty List\n"; return; }
        if(head->next==NULL){ delete (head); head=NULL; Tail=NULL; size--; return;   }
        cur=Tail; Tail=Tail->Prev ; Tail->next=NULL; free(cur); size--;
    }
    // function to remove front element from the list
    void pop_front(){
        if(head== nullptr || !size){ cout<<"Empty List\n"; return; }
        if(head->next==NULL){ delete (head); head=NULL; Tail=NULL; size--; return;   }
        cur=head;
        head=cur->next; cur->next->Prev=NULL;
        delete (cur); size--;
    }

};
int main()
{
    fast; // ashf gamed tenen
   /*  LinkedList one;
     one.insert(33); one.insert(1); one.insert(12); one.insert(43); one.insert(69);
     one.print();
     one.pop_back();
     one.print();
    one.pop_back();
    one.print();
    one.pop_back();
    one.print();
    one.pop_back();
    one.print();
    one.pop_back();
    one.print();
    one.push_front(111); one.insert(212); one.push_front(124);
    one.print();*/
    return 0;
}