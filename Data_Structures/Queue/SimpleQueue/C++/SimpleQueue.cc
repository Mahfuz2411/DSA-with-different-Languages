#include <bits/stdc++.h>
using namespace std;

class SimpleQueue {
private:
    vector<int> data;
public:
    void enqueue(int value);
    void dequeue();
    int front();
    int rear();
    bool isEmpty();
    int size();
    void display();
    void clear();
};


void SimpleQueue::enqueue(int value) {
    data.push_back(value);
}

void SimpleQueue::dequeue() {
    if (data.empty()) {
        throw out_of_range("Queue is empty");
    }
    data.erase(data.begin());
}

int SimpleQueue::front() {
    if (!data.empty()) {
        return data.front();
    }
    throw out_of_range("Queue is empty");
}

int SimpleQueue::rear() {
    if (!data.empty()) {
        return data.back();
    }
    throw out_of_range("Queue is empty");
}

bool SimpleQueue::isEmpty() {
    return data.empty();
}

int SimpleQueue::size() {
    return data.size();
}

void SimpleQueue::display() {
    if (data.empty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: [ ";
    for (int val : data) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

void SimpleQueue::clear() {
    data.clear();
    cout << "Queue cleared!\n";
}

int main() {
    SimpleQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl;

    return 0;
}