/*
 * Deque - Double-ended circular queue
 *
 * Operations: pushFront/pushBack O(1), popFront/popBack O(1), peek O(1)
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct {
    int arr[CAPACITY];
    int front;   /* index of the first element */
    int rear;    /* index one-past the last element */
    int count;
} Deque;

void init(Deque *d) {
    d->front = 0;
    d->rear  = 0;
    d->count = 0;
}

int isEmpty(Deque *d) { return d->count == 0; }
int isFull(Deque *d)  { return d->count == CAPACITY; }

void pushBack(Deque *d, int value) {
    if (isFull(d)) { printf("Deque is full!\n"); return; }
    d->arr[d->rear] = value;
    d->rear = (d->rear + 1) % CAPACITY;
    d->count++;
}

void pushFront(Deque *d, int value) {
    if (isFull(d)) { printf("Deque is full!\n"); return; }
    d->front = (d->front - 1 + CAPACITY) % CAPACITY;
    d->arr[d->front] = value;
    d->count++;
}

int popFront(Deque *d) {
    if (isEmpty(d)) { printf("Deque is empty!\n"); exit(1); }
    int val = d->arr[d->front];
    d->front = (d->front + 1) % CAPACITY;
    d->count--;
    return val;
}

int popBack(Deque *d) {
    if (isEmpty(d)) { printf("Deque is empty!\n"); exit(1); }
    d->rear = (d->rear - 1 + CAPACITY) % CAPACITY;
    int val = d->arr[d->rear];
    d->count--;
    return val;
}

int peekFront(Deque *d) {
    if (isEmpty(d)) { printf("Deque is empty!\n"); exit(1); }
    return d->arr[d->front];
}

int peekBack(Deque *d) {
    if (isEmpty(d)) { printf("Deque is empty!\n"); exit(1); }
    return d->arr[(d->rear - 1 + CAPACITY) % CAPACITY];
}

int main() {
    Deque d;
    init(&d);

    pushBack(&d, 1);
    pushFront(&d, 0);
    pushBack(&d, 2);

    printf("Front: %d, Back: %d\n", peekFront(&d), peekBack(&d));
    printf("Pop front: %d\n", popFront(&d));
    printf("Pop back: %d\n", popBack(&d));
    printf("Remaining front: %d\n", peekFront(&d));

    return 0;
}
