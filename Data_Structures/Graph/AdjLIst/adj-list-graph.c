#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in an adjacency list
struct gphNode {
    int dta;  // Data value of the node
    struct gphNode* nxt;  // Next pointer for the list
};

// Define a structure for a linked list
struct List {
    struct gphNode* head;  // Head pointer of the list
    struct gphNode* tail;  // Tail pointer of the list
    int size;  // Size of the list
};

// Define a structure for a vertex in a graph
struct verNode {
    struct verNode* p;  // Parent pointer (used in algorithms like BFS/DFS)
    struct verNode* nxt;  // Next pointer (used in adjacency list representation)
    int visit;  // Visited flag (used in graph traversal algorithms)
    int d, f, v;  // Discovery time, finishing time, and vertex number
    struct List* adjList;  // Adjacency list for the vertex
};

// Function to push a new node with a given value to the list
void push(struct List* list, int x) {
    struct gphNode* node = (struct gphNode*)malloc(sizeof(struct gphNode));
    node->dta = x;
    node->nxt = NULL;
    if (list->size == 0)
        list->head = node;
    else
        list->tail->nxt = node;
    list->tail = node;
    list->size++;
}

// Function to take input for the graph
void input_graph(struct verNode* vertex[], int n) {
    int m;
    printf("Enter the number of edges (m): ");
    scanf("%d", &m);
    
    for (int i = 1; i <= n; i++) {
        vertex[i] = (struct verNode*)malloc(sizeof(struct verNode));
        vertex[i]->adjList = (struct List*)malloc(sizeof(struct List));
        vertex[i]->adjList->head = NULL;
        vertex[i]->adjList->tail = NULL;
        vertex[i]->adjList->size = 0;
    }

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(vertex[u]->adjList, v);  // Add edge from vertex 'u' to vertex 'v'
    }
}

// Function to print the graph
void print_graph(struct verNode* vertex[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d -> ", i);
        struct gphNode* curr = vertex[i]->adjList->head;
        while (curr != NULL) {
            printf("%d ", curr->dta);
            curr = curr->nxt;
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    int n;
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);

    struct verNode* vertex[n+1];  // One-based indexing

    input_graph(vertex, n);
    printf("\nGraph Representation:\n");
    print_graph(vertex, n);

    return 0;
}
