/*
 * PriorityQueue - Min-heap based priority queue
 *
 * Operations: Push O(log n), Pop O(log n), Peek O(1)
 * Smallest value has highest priority.
 */

using System;

class PriorityQueue {
    private int[] heap;
    private int size;
    private int capacity;

    public PriorityQueue(int capacity = 100) {
        this.capacity = capacity;
        heap = new int[capacity];
        size = 0;
    }

    public bool IsEmpty() => size == 0;
    public int  Size()    => size;

    private void Swap(int i, int j) {
        int tmp = heap[i]; heap[i] = heap[j]; heap[j] = tmp;
    }

    private void HeapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                Swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }

    private void HeapifyDown(int i) {
        int smallest = i;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        if (left  < size && heap[left]  < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            Swap(i, smallest);
            HeapifyDown(smallest);
        }
    }

    public void Push(int value) {
        if (size == capacity) {
            Console.WriteLine("Priority queue is full!");
            return;
        }
        heap[size++] = value;
        HeapifyUp(size - 1);
    }

    public int Pop() {
        if (IsEmpty()) throw new InvalidOperationException("Priority queue is empty");
        int min = heap[0];
        heap[0] = heap[--size];
        if (size > 0) HeapifyDown(0);
        return min;
    }

    public int Peek() {
        if (IsEmpty()) throw new InvalidOperationException("Priority queue is empty");
        return heap[0];
    }

    static void Main() {
        PriorityQueue pq = new PriorityQueue();

        pq.Push(30);
        pq.Push(10);
        pq.Push(50);
        pq.Push(20);

        Console.WriteLine($"Peek (min): {pq.Peek()}");
        while (!pq.IsEmpty()) {
            Console.WriteLine($"Pop: {pq.Pop()}");
        }
    }
}
