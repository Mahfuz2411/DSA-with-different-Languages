/*
 * PriorityQueue - Min-heap based priority queue
 *
 * Operations: push O(log n), pop O(log n), peek O(1)
 * Smallest value has highest priority.
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

typedef struct {
    int heap[CAPACITY];
    int size;
} PriorityQueue;

void init(PriorityQueue *pq) { pq->size = 0; }

static void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

static void heapifyUp(PriorityQueue *pq, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->heap[i] < pq->heap[parent]) {
            swap(&pq->heap[i], &pq->heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

static void heapifyDown(PriorityQueue *pq, int i) {
    int smallest = i;
    int left     = 2 * i + 1;
    int right    = 2 * i + 2;

    if (left  < pq->size && pq->heap[left]  < pq->heap[smallest]) smallest = left;
    if (right < pq->size && pq->heap[right] < pq->heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

void push(PriorityQueue *pq, int value) {
    if (pq->size == CAPACITY) { printf("Priority queue is full!\n"); return; }
    pq->heap[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

int pop(PriorityQueue *pq) {
    if (pq->size == 0) { printf("Priority queue is empty!\n"); exit(1); }
    int min = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapifyDown(pq, 0);
    return min;
}

int peek(PriorityQueue *pq) {
    if (pq->size == 0) { printf("Priority queue is empty!\n"); exit(1); }
    return pq->heap[0];
}

int isEmpty(PriorityQueue *pq) { return pq->size == 0; }

int main() {
    PriorityQueue pq;
    init(&pq);

    push(&pq, 30);
    push(&pq, 10);
    push(&pq, 50);
    push(&pq, 20);

    printf("Peek (min): %d\n", peek(&pq));
    while (!isEmpty(&pq)) {
        printf("Pop: %d\n", pop(&pq));
    }

    return 0;
}
