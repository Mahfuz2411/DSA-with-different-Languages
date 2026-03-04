/*
 * SimpleQueue - Basic FIFO queue using array with element shifting
 *
 * Operations : enqueue O(1), dequeue O(n), front/rear O(1)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int count;
} SimpleQueue;

void init(SimpleQueue *q) {
    q->count = 0;
}

int isEmpty(SimpleQueue *q) {
    return q->count == 0;
}

int isFull(SimpleQueue *q) {
    return q->count == MAX_SIZE;
}

void enqueue(SimpleQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
        return;
    }
    q->data[q->count++] = value;
}

int dequeue(SimpleQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int val = q->data[0];
    for (int i = 0; i < q->count - 1; i++) {
        q->data[i] = q->data[i + 1];
    }
    q->count--;
    return val;
}

int front(SimpleQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->data[0];
}

int rear(SimpleQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->data[q->count - 1];
}

int main() {
    SimpleQueue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d, Rear: %d\n", front(&q), rear(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Front after dequeue: %d\n", front(&q));

    return 0;
}
