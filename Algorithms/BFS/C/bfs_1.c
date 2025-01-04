#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000002  // Maximum number of vertices

// Adjacency list node structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[N];  // Array of adjacency lists
int n, m;        // Number of vertices and edges

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(int a, int b) {
    Node* newNode = createNode(b);
    newNode->next = graph[a];
    graph[a] = newNode;

    newNode = createNode(a);
    newNode->next = graph[b];
    graph[b] = newNode;
}

// Function to take graph input
void graphInput() {
    printf("Enter the number of nodes & edges (n m):\n");
    scanf("%d %d", &n, &m);

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
}

// BFS function
void bfs(int start) {
    bool visited[N] = {false};  // Initialize all nodes as unvisited
    int queue[N], front = 0, rear = 0;

    // Enqueue the starting node
    queue[rear++] = start;
    visited[start] = true;

    printf("BFS traversal starting from node %d:\n", start);

    while (front < rear) {
        int node = queue[front++];  // Dequeue the front node
        printf("%d ", node);

        // Visit all unvisited adjacent nodes
        Node* temp = graph[node];
        while (temp) {
            int next = temp->vertex;
            if (!visited[next]) {
                queue[rear++] = next;  // Enqueue the unvisited node
                visited[next] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    graphInput();
    int start;
    printf("Start node?\n");
    scanf("%d", &start);
    bfs(start);
    return 0;
}
