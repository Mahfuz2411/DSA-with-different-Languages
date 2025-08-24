#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int *arr;       // dynamic array for queue
    int capacity;   // maximum size of queue
    int front;      // index of front element
    int rear;       // index of rear element
    int count;      // current number of elements

public:
    CircularQueue(int size);   // constructor
    ~CircularQueue();          // destructor

    void enqueue(int value);
    void dequeue();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    void clear();
};

// Constructor
CircularQueue::CircularQueue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor
CircularQueue::~CircularQueue() {
    delete[] arr;
}

// Enqueue operation
void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue " << value << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
}

// Dequeue operation
void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue.\n";
        return;
    }
    front = (front + 1) % capacity;
    count--;
}

// Get front element
int CircularQueue::getFront() {
    if (isEmpty()) throw out_of_range("Queue is empty");
    return arr[front];
}

// Get rear element
int CircularQueue::getRear() {
    if (isEmpty()) throw out_of_range("Queue is empty");
    return arr[rear];
}

// Check if queue is empty
bool CircularQueue::isEmpty() {
    return (count == 0);
}

// Check if queue is full
bool CircularQueue::isFull() {
    return (count == capacity);
}

// Get current size
int CircularQueue::size() {
    return count;
}

// Display elements
void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % capacity] << " ";
    }
    cout << endl;
}

// Clear the queue
void CircularQueue::clear() {
    front = 0;
    rear = -1;
    count = 0;
    cout << "Queue cleared!\n";
}


int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cout << "Front: " << cq.getFront() << ", Rear: " << cq.getRear() << endl;

    cq.dequeue();
    cq.dequeue();

    cq.display();
    cout << "Front after dequeue: " << cq.getFront() << endl;

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    cq.clear();
    cq.display();

    return 0;
}
