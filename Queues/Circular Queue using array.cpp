#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
using namespace std;
#define cin(vec) for(auto& i : vec) cin >> i;
class Queue{
private:
int size=0;
int cap=100;
int front=-1,rear=-1;
int arr[100];
bool isEmpty(){
    if(front==rear && rear==-1) return 1; return 0;
}
bool isFull(){
    if((rear==cap-1 && !front) || front==rear+1  ) return 1; return 0;
}
public:
void enqueue(int element){
    if(isFull()){ cout<<"Full\n";  return; }
    if(isEmpty()){
        front++; arr[++rear]=element;
    }
    else{
        if(rear==cap-1){
            rear=0; arr[rear]=element;
        }
        else {
            arr[++rear] = element;
        }
    }
    size++;
}
void dequeue(){
    if(isEmpty()){ cout<<"Empty\n"; return; }
    if(front==rear){ front=rear=-1; size=0; return; }
    if(front==cap-1){
        front=0;
    }
    else{
        front++;
    }
    size--;
}
int top(){
    if(isEmpty()) return -1;
    return arr[front];
}
void Print(){
    if(isEmpty()){ cout<<"Empty\n"; return; }
    if(front<=rear){
        for(int i=front;i<=rear;i++) cout<<arr[i]<<" ";   cout<<endl;
    }
    else{
        for(int i=front;i<cap;i++)   cout<<arr[i]<<" ";
        for(int i=0;i<=rear;i++)     cout<<arr[i]<<" "; cout<<endl;
    }
}
};
void solve()
{
    ll n,i=0,j=0,cnt=0;
  /*  Queue x;
    x.enqueue(1);
    x.enqueue(2);
    x.enqueue(2);
    x.enqueue(2);
    x.enqueue(2);
    x.Print();
    x.dequeue();  x.dequeue();
    x.Print();
    x.enqueue(12);
    x.enqueue(122);
    x.Print();
    x.enqueue(1111);*/
}
int main()
{
    fast;
    ll test_case=1 ;  //    cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}