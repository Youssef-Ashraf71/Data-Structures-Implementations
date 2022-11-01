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

// Stack Implementation Using Array

class Stack{
private:
    int Top=-1; // points to the first element in stack
    int it;  // points to iterate the stack
   static const int size=10000;
   int data[size];
public:
    // function to Push an element at the Top of the stack
    void push(int value ){
        if(Top==size-1){cout<<"Stack Overflow"<<endl; return; }
        Top++; data[Top]=value;
    }
// function to display the data stored in the stack
    void print(){
        if(Top==-1){ cout<<"Empty Stack"<<endl; return; }
        cout<<"Size: "<<Top+1<<endl;
        for(int i=Top;i>=0;i--){
            cout<<data[i]; (!i) ? cout<<endl:cout<<" ";
        }
    }
    // function to remove Top element from the stack and return it
    int pop(){
        if(Top==-1){ cout<<"Empty Stack"<<endl; return -1;}
        return data[Top--];
    }
    // function to return the element at the top of the stack
    int top(){
         if(Top==-1){ cout<<"Empty Stack"<<endl; return -1;}
        return data[Top];
    }
};
void solve()
{
    ll n,i=0,j=0,cnt=0;
      Stack one;
      one.push(222);
      one.push(12); one.push(212);
      one.print(); one.push(11); one.print();
      cout<<one.top()<<endl;
      one.pop();
      cout<<one.top()<<endl;
      one.print();




}
int main()
{
    fast; // ashf gamed tenen
    //freopen("window.in", "r", stdin);   // for file reading
    ll test_case=1 ;    //  cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}