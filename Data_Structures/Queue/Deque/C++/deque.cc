/*
 * Deque - Double-ended circular array queue
 *
 * Operations: pushFront/pushBack O(1), popFront/popBack O(1), peek O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Deque {
private:
    int* arr;
    int cap;
    int front;  /* index of first element */
    int rear;   /* index one-past the last element */
    int count;

public:
    Deque(int capacity = 10)
        : cap(capacity), front(0), rear(0), count(0) {
        arr = new int[cap];
    }

    ~Deque() { delete[] arr; }

    bool isEmpty() const { return count == 0; }
    bool isFull()  const { return count == cap; }
    int  size()    const { return count; }

    void pushBack(int value) {
        if (isFull()) { cout << "Deque is full!\n"; return; }
        arr[rear] = value;
        rear = (rear + 1) % cap;
        count++;
    }

    void pushFront(int value) {
        if (isFull()) { cout << "Deque is full!\n"; return; }
        front = (front - 1 + cap) % cap;
        arr[front] = value;
        count++;
    }

    int popFront() {
        if (isEmpty()) throw out_of_range("Deque is empty");
        int val = arr[front];
        front = (front + 1) % cap;
        count--;
        return val;
    }

    int popBack() {
        if (isEmpty()) throw out_of_range("Deque is empty");
        rear = (rear - 1 + cap) % cap;
        int val = arr[rear];
        count--;
        return val;
    }

    int peekFront() const {
        if (isEmpty()) throw out_of_range("Deque is empty");
        return arr[front];
    }

    int peekBack() const {
        if (isEmpty()) throw out_of_range("Deque is empty");
        return arr[(rear - 1 + cap) % cap];
    }
};

int main() {
    Deque d(10);

    d.pushBack(1);
    d.pushFront(0);
    d.pushBack(2);

    cout << "Front: " << d.peekFront() << ", Back: " << d.peekBack() << endl;
    cout << "Pop front: " << d.popFront() << endl;
    cout << "Pop back: "  << d.popBack()  << endl;
    cout << "Remaining front: " << d.peekFront() << endl;

    return 0;
}
