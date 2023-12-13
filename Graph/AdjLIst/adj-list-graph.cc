// You can't do anything until you try

// Include necessary C++ standard library headers
#include<bits/stdc++.h>
using namespace std;

// Define constants for the maximum number of vertices and a modulo value
const int N = 1e6+2, MOD = 1e9+2;

// Declare global variables for the number of vertices and edges
int n, m;

// Define a structure for a vertex in a graph
struct verNode{
    verNode* p;   // Parent pointer (used in algorithms like BFS/DFS)
    verNode* nxt;  // Next pointer (used in adjacency list representation)
    int visit;     // Visited flag (used in graph traversal algorithms)
    int d, f, v;   // Discovery time, finishing time, and vertex number

    // Constructor for the structure
    verNode(int i): p(nullptr), nxt(nullptr), visit(0), d(0), f(0), v(i) {}
};

// Define a structure for a node in an adjacency list
struct gphNode{
    int dta;      // Data value of the node
    gphNode* nxt;  // Next pointer for the list

    // Constructors for the structure
    gphNode(): dta(0), nxt(nullptr) {}
    gphNode(int x): dta(x), nxt(nullptr) {}
};

// Define a structure for a linked list
struct List{
    gphNode* head;  // Head pointer of the list
    gphNode* tail;  // Tail pointer of the list
    int size;       // Size of the list

    // Constructor for the list
    List():head(nullptr), tail(nullptr), size(0) {}

    // Function to push a new node with a given value to the list
    void push(int x) {
        gphNode* node = new gphNode(x);
        if(size==0) head = node;
        else tail->nxt = node;
        tail = node;
        size++;
    }

    // Function to get the value of the node at a given position in the list
    int getNodeVal(int i) {
        gphNode* u = head;
        for(int k=1; k<i; k++) {
            u = u->nxt;
        }
        return u->dta;
    }
};

// Define a structure for a queue of vertices
struct Queue{
    verNode* first;  // Front of the queue
    verNode* last;   // Rear of the queue
    int size;        // Size of the queue

    // Constructor for the queue with an initial vertex
    Queue(verNode* u): first(u), last(u), size(1) {}

    // Function to push a new vertex to the queue
    void push_node(verNode* u) {
        if(size==0) first = u;
        else last->nxt = u;
        last = u;
        size++;
    }

    // Function to pop a vertex from the queue
    verNode* pop_node(){
        if(size==0) return nullptr;
        verNode* node = first;
        first = first->nxt;
        size--;
        return node;
    }
};

// Array of vertex pointers
verNode* vertex[N];

// Array of adjacency lists
List* graph[N];

// Function to input the graph from the standard input
void graphInput() {
    cin>>n>>m;  // Input the number of vertices and edges
    for(int i=1; i<=n; i++) {
        // Initialize each vertex with its number
        verNode* u = new verNode(i);
        u->nxt = nullptr;
        vertex[i] = u;
        graph[i] = new List();  // Initialize the adjacency list for each vertex
    }

    for(int i=1; i<=m; i++) {
        int a, b;   cin>>a>>b;
        graph[a]->push(b);  // Add edge from vertex 'a' to vertex 'b'
    }
}

// Main function
int main(int argc, char const *argv[]){
    graphInput();  // Call the function to input the graph
    return 0;
}
