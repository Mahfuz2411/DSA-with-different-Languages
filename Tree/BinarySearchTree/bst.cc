//You can't do anything until you try
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* parent;
  Node* left;
  Node* right;
};

class Tree{
    private:
        Node* r;
        int n;
        Node* newNode(int);

    public:
        Tree();
        int find(int);
        bool add(int);
        Node* findLast(int);
        bool addChild(Node*, Node*);
        void postOrder();
        void preOrder();
        void inOrder();
};

Tree::Tree(){
    r = nullptr;
    n = 0;
}

Node* Tree::newNode(int x){
    Node* node = new Node;
    node->data = x;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    return node;
}

int Tree::find(int x){
    Node* w = r;
    Node* z = nullptr;

    while(w != nullptr)
        if(x < w->data) {z = w; w = w->left;}   //only place to find z;
        else if(x > w->data) w = w->right;
        else return w->data;         //x is the tree;
    if(z == nullptr) return NULL; 
    return z->data;          //Only if  x is absent
}

/**
 **Add Functions**
**/

bool Tree::add(int x){
    return addChild(findLast(x), newNode(x));
}

Node* Tree::findLast(int x){
    Node* w = r;
    Node* prev = nullptr;

    while(w != nullptr){
        prev = w;
        if(x < w->data) w = w->left;
        else if(x > w->data) w = w->right;
        else return w;
    }
    return prev;
}

bool Tree::addChild(Node* p, Node* u){
    if(p==nullptr) r = u;
    else{
        if(u->data < p->data) p->left = u;
        else if(u->data > p->data) p->right = u;
        else return false;
        u->parent = p;
    }
    ++n;
    return true;
}

/**
 **Remove Functions**
 *! will be added soon
**/



/**
 **Travarsal Functions**
**/
void Tree::postOrder(){
    Node* u = r;
    Node* prev = nullptr;
    Node* nxt;

    while(u != nullptr){
        if(prev == u->parent){
            if(u->left != nullptr) { nxt = u->left;}
            else if(u->right!=nullptr) { nxt = u->right; }
            else {cout<<u->data<<' ';    nxt = u->parent; }
        }else if(prev ==u->left){
            
            if(u->right!=nullptr) nxt = u->right;
            else {cout<<u->data<<' ';    nxt = u->parent;}
        }else {cout<<u->data<<' ';    nxt = u->parent;}
        prev = u;
        u = nxt;
    }
    cout<<'\n';
}

void Tree::preOrder(){
    Node* u = r;
    Node* prev = nullptr;
    Node* nxt;

    while(u != nullptr){
        if(prev == u->parent){
            if(u->left != nullptr) { nxt = u->left; }
            else if(u->right!=nullptr) { nxt = u->right;  }
            else { nxt = u->parent;  }
            cout<<u->data<<' ';
        }else if(prev == u->left){
            if(u->right != nullptr) { nxt = u->right; }
            else { nxt = u->parent; }
        }else {  nxt = u->parent;  } 
        prev = u;
        u = nxt;
    }
    cout<<'\n';
}

void Tree::inOrder(){
    Node* u = r;
    Node* prev = nullptr;
    Node* nxt;

    while(u != nullptr){
        if(prev == u->parent){
            if(u->left != nullptr) {nxt = u->left; }
            else if(u->right!=nullptr) {cout<<u->data<<' '; nxt = u->right; }
            else {cout<<u->data<<' '; nxt = u->parent; }
        }else if(prev == u->left){
            cout<<u->data<<' ';
            if(u->right != nullptr) { nxt = u->right; }
            else { nxt = u->parent; }
        }else { nxt = u->parent; } 
        prev = u;
        u = nxt;
    }
    cout<<'\n';
}


int main(){
    Tree ob;
    ob.add(5);
    ob.add(6);
    ob.add(1);
    ob.add(2);
    ob.add(3);
    cout<<ob.find(1)<<endl;
    ob.preOrder();
    ob.inOrder();
    ob.postOrder();
    return 0;
}