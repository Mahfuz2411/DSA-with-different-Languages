/**
 * ** Prerequisite to understand this code
 *  -> Object Oriented Programming
*/
#include <iostream>
using namespace std;

struct Node{
  int dta;      //stores data
  Node* nxt;    //stores pointers of next node
};

class List{
private:
  Node* head;    //stores pointers of first node
  Node* tail;    //stores pointers of last node
  int n;

  //At first we need to set a program that can create nodes
  Node* newNode(int x){
    Node* node = new Node;
    node->dta = x;
    node->nxt = nullptr;

    return node;

    //if you want to write 'newNode' in one line then
    //return new Node{x, nullptr};
  }

public:
  List();    //Constructor;

  //Stack interface
  void Push(int x);
  int Pop();

  //Dequeqe interface
  void Add(int x);
  int Remove();

  void PrintList();    //For printing the List 
};

List::List(){
  //Initializing variables;
  n = 0;
  head = nullptr;
  tail = nullptr;
}


//*************STACK INTERFACE****************
void List::Push(int x){
  Node* u = newNode(x);
  u->nxt = head;
  head = u;
  if(n==0) tail = u;
  ++n;
  return;    //As it is a void function;
}

int List::Pop(){
  if(n==0) return 0;   //No values to remove;
  int temp = head->dta;
  head = head->nxt;
  --n;
  return temp;
}


//************QUEUE INTERFACE***************
void List::Add(int x){
  Node* u = newNode(x);
  if(n==0) head = u;
  else tail->nxt = u;
  tail = u;
  ++n;
  return;
}

int List::Remove(){
  return Pop();    //Same as pop()
}


//*************PRINTING****************
void List::PrintList(){
  Node* u = head;
  cout<<"[ ";
  while(u!=nullptr){
    cout<<u->dta<<' ';
    u = u->nxt;
  }
  cout<<"]\n";
  return;
}
int main() {
  List ob;
  ob.Push(5);
  ob.Push(4);
  ob.Push(3);
  ob.Push(2);
  ob.Push(1);

  ob.Add(5);
  ob.Add(4);
  ob.Add(3);
  ob.Add(2);
  ob.Add(1);

  // ob.Pop();
  // ob.Pop();
  // ob.Pop();
  // ob.Pop();
  // ob.Pop();
  // ob.Pop();

  // ob.Remove();
  // ob.Remove();
  // ob.Remove();
  // ob.Remove();
  // ob.Remove();
  // ob.Remove();
  
  ob.PrintList();
  return 0;
}

//Comment If you find any mistake;