/*
 * SimpleQueue - Basic FIFO queue
 *
 * Operations: Enqueue O(1), Dequeue O(n), Front/Rear O(1)
 */

using System;

class SimpleQueue {
    private int[] data;
    private int count;
    private int capacity;

    public SimpleQueue(int capacity = 100) {
        this.capacity = capacity;
        data = new int[capacity];
        count = 0;
    }

    public void Enqueue(int value) {
        if (count == capacity) {
            Console.WriteLine("Queue overflow!");
            return;
        }
        data[count++] = value;
    }

    public int Dequeue() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        int val = data[0];
        for (int i = 0; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
        return val;
    }

    public int Front() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        return data[0];
    }

    public int Rear() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        return data[count - 1];
    }

    public bool IsEmpty() => count == 0;
    public int Size() => count;

    static void Main() {
        SimpleQueue q = new SimpleQueue();

        q.Enqueue(10);
        q.Enqueue(20);
        q.Enqueue(30);

        Console.WriteLine($"Front: {q.Front()}, Rear: {q.Rear()}");
        Console.WriteLine($"Dequeue: {q.Dequeue()}");
        Console.WriteLine($"Front after dequeue: {q.Front()}");
    }
}
