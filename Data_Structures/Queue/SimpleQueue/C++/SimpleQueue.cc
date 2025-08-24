#include <bits/stdc++.h>
using namespace std;

class SimpleQueue {
private:
    int* data;       // dynamic array for queue
    int capacity;    // total capacity
    int count;       // current number of elements

public:
    SimpleQueue(int size = 100); // constructor with default capacity
    ~SimpleQueue();              // destructor

    void enqueue(int value);
    void dequeue();
    int front();
    int rear();
    bool isEmpty();
    int size();
    void display();
    void clear();
};

// Constructor
SimpleQueue::SimpleQueue(int size) {
    capacity = size;
    data = new int[capacity];
    count = 0;
}

// Destructor
SimpleQueue::~SimpleQueue() {
    delete[] data;
}

// Enqueue -> insert at end
void SimpleQueue::enqueue(int value) {
    if (count == capacity) {
        cout << "Queue overflow! Cannot enqueue " << value << endl;
        return;
    }
    data[count++] = value;
}

// Dequeue -> remove from front (O(n) shift)
void SimpleQueue::dequeue() {
    if (count == 0) {
        throw out_of_range("Queue is empty");
    }
    for (int i = 0; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;
}

// Get front element
int SimpleQueue::front() {
    if (count == 0) throw out_of_range("Queue is empty");
    return data[0];
}

// Get rear element
int SimpleQueue::rear() {
    if (count == 0) throw out_of_range("Queue is empty");
    return data[count - 1];
}

// Check if empty
bool SimpleQueue::isEmpty() {
    return (count == 0);
}

// Get current size
int SimpleQueue::size() {
    return count;
}

// Display elements
void SimpleQueue::display() {
    if (count == 0) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: [ ";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << "]" << endl;
}

// Clear all elements
void SimpleQueue::clear() {
    count = 0; // just reset count
    cout << "Queue cleared!\n";
}


int main() {
    SimpleQueue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;

    q.dequeue();
    q.display();

    cout << "Front element after dequeue: " << q.front() << endl;

    q.clear();
    q.display();

    return 0;
}
