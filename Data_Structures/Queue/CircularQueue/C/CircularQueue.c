/*
 * CircularQueue - Fixed-capacity circular array queue
 *
 * Operations: enqueue O(1), dequeue O(1), getFront/getRear O(1)
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

typedef struct {
    int arr[CAPACITY];
    int front;
    int rear;
    int count;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = 0;
    q->rear  = -1;
    q->count = 0;
}

int isEmpty(CircularQueue *q) { return q->count == 0; }
int isFull(CircularQueue *q)  { return q->count == CAPACITY; }

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % CAPACITY;
    q->arr[q->rear] = value;
    q->count++;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->count--;
    return val;
}

int getFront(CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); exit(1); }
    return q->arr[q->front];
}

int getRear(CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); exit(1); }
    return q->arr[q->rear];
}

int main() {
    CircularQueue cq;
    init(&cq);

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);

    printf("Front: %d, Rear: %d\n", getFront(&cq), getRear(&cq));
    printf("Dequeue: %d\n", dequeue(&cq));
    printf("Dequeue: %d\n", dequeue(&cq));

    /* Wrap-around test */
    enqueue(&cq, 60);
    enqueue(&cq, 70);
    printf("Front: %d, Rear: %d\n", getFront(&cq), getRear(&cq));

    return 0;
}
