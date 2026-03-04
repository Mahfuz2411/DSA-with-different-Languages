/*
 * PriorityQueue - Min-heap based priority queue
 *
 * Operations: push O(log n), pop O(log n), peek O(1)
 * Smallest value has highest priority.
 */

#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        if (left  < n && heap[left]  < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    bool isEmpty() const { return heap.empty(); }
    int  size()    const { return (int)heap.size(); }

    void push(int value) {
        heap.push_back(value);
        heapifyUp((int)heap.size() - 1);
    }

    int pop() {
        if (isEmpty()) throw out_of_range("Priority queue is empty");
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!isEmpty()) heapifyDown(0);
        return min;
    }

    int peek() const {
        if (isEmpty()) throw out_of_range("Priority queue is empty");
        return heap[0];
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Peek (min): " << pq.peek() << endl;
    while (!pq.isEmpty()) {
        cout << "Pop: " << pq.pop() << endl;
    }

    return 0;
}
