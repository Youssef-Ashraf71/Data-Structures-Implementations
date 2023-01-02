#ifndef MY_TREE_H
#define MY_TREE_H
#define ll long long
#include <bits/stdc++.h>
#include <vector>
using namespace std;
template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{
private:

    Node<T>*root; // our root
    Node<T>* removed; // memoize in it the removed node
    ll size=0;   // track the number of nodes in the tree
    ll height=0;
    Node<T>* Binary_Search(vector<T>&arr,ll l,ll r){
        if(l>r) return NULL;
        ll seg=(r-l+1); // length of our current array
        ll  mid=((l+r)>>1) + (seg%2==0); // similar to binary search algo
        Node<T>* NewNode=new  Node<T>(arr[mid]); // create a node with our new middle and so on
        NewNode->left=Binary_Search(arr,l,mid-1); // backtrack the new subtree to our left branch
        NewNode->right=Binary_Search(arr,mid+1,r); // backtrack the new subtree to our right branch
        return NewNode;  // returning each subtree to the call it came from
    }
    void Inorder(Node<T>*node,vector<T>&arr){
        // base case
        if (!node) return;
        // transition
        Inorder(node->left,arr);   // till reaching most left leaf
        arr.push_back(node->data);  // push our current to the vector
        Inorder(node->right,arr); // means you have already processed the left subtree and root so go process right subtree
    }
    void Preorder(Node<T>*node,vector<T>&arr){
        // base case
        if (!node) return;
        // transition
        arr.push_back(node->data); // push our current to the vector
        Preorder(node->left,arr); //
        Preorder(node->right,arr);
    }
    void Postorder(Node<T>*node,vector<T>&arr){
        // base case
        if (!node) return;
        // transition
        Postorder(node->left,arr);  // till reaching most left leaf
        Postorder(node->right,arr); // means you have already processed the left subtree so go process right then root
        arr.push_back(node->data); // push our current to the vector
    }
    ll go_get_depth(Node<T>* node){
        if(node==NULL) return 0; // if no tree found
        ll l,r; l=r=0;
        if(node->left){
            l=go_get_depth(node->left)+1; // go get height of our left subtree + myself (1)
        }
        else{
            l++;    // reached a leaf so count it
        }
        if(node->right){
            r=go_get_depth(node->right)+1; // go get height of our right subtree + myself (1)
        }
        else{
            r++; // reached a leaf so count it
        }
        return max(l,r); // backtrack our maximum height of our current subtree
    }
    void destroy(Node<T>* node){
        if(node==NULL) return; // no tree found
        if(node->left)  destroy(node->left); // if a left subtree found go destroy it
        if(node->right) destroy(node->right); // if a right subtree found go destroy it
        delete node;  // deleting our current node
    }
    Node<T>* Delete_Node(Node<T>* it,T key){
            if(!it) return it;
            if(key<it->data){
                it->left=Delete_Node(it->left,key); // if our target is smaller go to left subtree
            }
            else if(key>it->data){
                it->right=Delete_Node(it->right,key); // if our target is bigger go to right subtree
            }
            else{
                removed=it; // memoize our removed node
                if(!it->left){
                    Node<T>* tmp=it->right; delete it;
                    return tmp;  // link our old subtree to the right child
                }
                else if(!it->right){
                    Node<T>* tmp=it->left; delete it;
                    return tmp;  // link our old subtree to the left child
                }
                else{
                    // means 2 child found
                    T mini=Get_Successor(it->right); // go get the min in right subtree
                    it->data=mini;
                    it->right=Delete_Node(it->right,mini);
                }
            }
            return it;
    }
    Node<T>* Delete_Node_node(Node<T>* it,Node<T>* node){
        if(!it) return it;
        if(node->data<it->data){
            it->left=Delete_Node_node(it->left,node); // if our target is smaller go to left subtree
        }
        else if(node->data>it->data){
            it->right=Delete_Node_node(it->right,node); // if our target is bigger go to right subtree
        }
        else{
            removed=it;  // memoize our removed node
            if(!it->left){
                Node<T>* tmp=it->right; delete it;
                return tmp; // link our old subtree to the right child
            }
            else if(!it->right){
                Node<T>* tmp=it->left; delete it;
                return tmp;  // link our old subtree to the left child
            }
            else{
                // means 2 child found
                Node<T>* mini=Get_Successor_node(it->right);  // go get the min in right subtree
                it->data=mini;
                it->right=Delete_Node(it->right,mini);
            }
        }
        return it;
    }
    T Get_Successor(Node<T>* node){
        Node<T>* it=node; stack<Node<T>*>stk;
            // reach the most left subtree
            while (it){
                stk.push(it); it=it->left;
            }
            // then visit its root so that is the minimum element in our subtree
            if(it==NULL and stk.size()){
                it=stk.top(); stk.pop();
            }
             return it->data; // return min element
    }
    Node<T>* Get_Successor_node(Node<T>* node){
        Node<T>* it=node; stack<Node<T>*>stk;
        // reach the most left subtree
        while (it){
            stk.push(it); it=it->left;
        }
        // then visit its root so that is the minimum element in our subtree
        if(it==NULL and stk.size()){
            it=stk.top(); stk.pop();
        }
        return it; // return min element
    }
public:
    MyTree(){
        root= nullptr; size=0; height=0;
    }
    MyTree(std::vector<T> elements){
        sort(elements.begin(),elements.end()); // to make it a balanced BST
        root=Binary_Search(elements,0,elements.size()-1); size=elements.size();
    }
    void insert(T key){
        Node<T>*it1 = root,*it2=NULL;
        Node<T>* newnode = new Node<T>(key);
        // using 2 ptrs cur & prev
        while (it1 != NULL) {
            it2 = it1;  // store cur in prev for the next iteration
            if (key < it1->data)     // if our target is smaller go to left subtree
                it1 = it1->left;
            else if( key >it1->data)    // if our target is bigger go to right subtree
                it1 = it1->right;
        }
        if (it2 == NULL)
        {
            it2 = newnode; root=newnode;  // if trees is empty and this is the first node to be inserted
        }
        else if (key < it2->data)
            it2->left = newnode; // insert the node at left child
        else if(key > it2->data)
            it2->right = newnode; // insert the node at right child
        size++;
    }
    void insert(const Node<T> node){
        Node<T>*it1 = root,*it2=NULL;
        // using 2 ptrs cur & prev
        while (it1 != NULL) {
            it2 = it1; // store cur in prev for the next iteration
            if (node.data < it1->data)   // if our target is smaller go to left subtree
                it1 = it1->left;
            else if( node.data >it1->data)   // if our target is bigger go to right subtree
                it1 = it1->right;
        }
        if (it2 == NULL)
        {
            it2 = node; root=node;  // if trees is empty and this is the first node to be inserted
        }
        else if (node.data < it2->data)  // insert the node at left child
            it2->left = node;
        else if(node.data > it2->data)   // insert the node at right child
            it2->right = node;
        size++;
    }

    const Node<T>* search(T key){
        Node<T>* it; it=root;
        if(!it) return NULL;
        while (it){
            if(it->data==key){    // if target is found
                break;
            }
            if(key<it->data){
                it=it->left;  // if target is smaller go search at left subtree
            }
            else{
                it=it->right;  // if target is bigger go search at right subtree
            }
        }
        return it;   // return target
    }

     const Node<T>* delete_node(T key){
         size--;
         root=Delete_Node(root,key); return removed;
    }

    const Node<T>* delete_node(const Node<T> node){
        size--;
        root=Delete_Node_node(root,node); return removed;
    }

    bool isBST(){
    if(!root) return 0;
    vector<T>mytree; Inorder(root,mytree);
        if(is_sorted(mytree.begin(),mytree.end())) return 1;  // if the inorder vector is sorted it means that it is a BST
        return 0;
    }

    std::vector<T> inorder_rec(){
        vector<T>ans;
        if(!root) return ans;
        Inorder(root,ans);
        return ans;
    }

    std::vector<T> preorder_rec(){
        vector<T>ans;
      //  if(!root) return ans;
        Preorder(root,ans);
        return ans;
    }

    std::vector<T> postorder_rec(){
        vector<T>ans;
        if(!root) return ans;
        Postorder(root,ans);
        return ans;
    }

    std::vector<T> inorder_it(){
    vector<T>ans;
    if(!root) return ans;
     Node<T>* it=root; stack<Node<T>*>stk;
     while (it || stk.size()){
         // reach the most left subtree
         while (it){
             stk.push(it); it=it->left;
         }
         // then visit its root
         if(it==NULL and stk.size()){
             it=stk.top(); stk.pop();
         }
         ans.push_back(it->data);
         // then its right subtree >> behaviour: Left - root - Right
         it=it->right;
     }
        return ans;
    }

    std::vector<T> preorder_it(){
        vector<T>ans;
        if(!root) return ans ;
        Node<T>* it; stack<Node<T>*>stk; stk.push(root);
        while (stk.size()){
            // reach the most left subtree
            it=stk.top();  stk.pop();
            ans.push_back(it->data); // print the root >> as root - left - right
            if(it->right) stk.push(it->right);  // such that the left is popped first before the right node
            if(it->left)  stk.push(it->left);
        }
        return ans;
    }

    std::vector<T> postorder_it(){
        vector<T>ans;
        if(!root) return ans ;
        Node<T>* it=root; Node<T>*prev=NULL; stack<Node<T>*>stk;
        while (it || stk.size()){
            if(it){
                stk.push(it); it=it->left;
            }
            else{
                it=stk.top();
                if(it->right==NULL){ // traversed right subtree
                    ans.push_back(it->data);
                    prev=it; stk.pop(); it=nullptr;
                }
                else if(it->right==prev){ // backtracking to the parent where we came from so now we are processing the parent
                    ans.push_back(it->data);
                    prev=it; stk.pop(); it= nullptr;
                }
                else{
                    it=it->right;
                }
            }
        }
        return ans;
    }

    std::vector<T> breadth_traversal(){
        vector<T>ans;
        if(!root) return ans ;
        queue<Node<T>*>que;   que.push(root);
        while (!que.empty()){
            Node<T>* cur=que.front(); que.pop();
            ans.push_back(cur->data); // push our current to vector
            if(cur->left) que.push(cur->left); // if current node has a left child push it in the queue
            if(cur->right) que.push(cur->right); // if current node has a right child push it in the queue
        }
        return ans;
    }

    int get_size(){
        return size;
    }

    int get_height(){
    // height is number of edges from root to furthest leaf
        return  go_get_depth(root)-1;
    }

    void clear(){
        // calling the function destroy which delete all nodes recursively
        destroy(root);// then reset size, height and root
        size=0; height=0; root= nullptr;
    }
    ~MyTree(){
        clear();
    }
};



#endif