/*
 * PriorityQueue - Min-heap based priority queue
 *
 * Operations: push O(log n), pop O(log n), peek O(1)
 * Smallest value has highest priority.
 */

public class PriorityQueue {
    private int[] heap;
    private int size;
    private int capacity;

    public PriorityQueue(int capacity) {
        this.capacity = capacity;
        heap = new int[capacity];
        size = 0;
    }

    private void swap(int i, int j) {
        int tmp = heap[i]; heap[i] = heap[j]; heap[j] = tmp;
    }

    private void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }

    private void heapifyDown(int i) {
        int smallest = i;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        if (left  < size && heap[left]  < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(i, smallest);
            heapifyDown(smallest);
        }
    }

    public boolean isEmpty() { return size == 0; }
    public int size()        { return size; }

    public void push(int value) {
        if (size == capacity) {
            System.out.println("Priority queue is full!");
            return;
        }
        heap[size++] = value;
        heapifyUp(size - 1);
    }

    public int pop() {
        if (isEmpty()) throw new RuntimeException("Priority queue is empty");
        int min = heap[0];
        heap[0] = heap[--size];
        if (size > 0) heapifyDown(0);
        return min;
    }

    public int peek() {
        if (isEmpty()) throw new RuntimeException("Priority queue is empty");
        return heap[0];
    }

    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(10);

        pq.push(30);
        pq.push(10);
        pq.push(50);
        pq.push(20);

        System.out.println("Peek (min): " + pq.peek());
        while (!pq.isEmpty()) {
            System.out.println("Pop: " + pq.pop());
        }
    }
}
