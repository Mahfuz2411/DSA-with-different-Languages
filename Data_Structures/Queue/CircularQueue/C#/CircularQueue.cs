/*
 * CircularQueue - Fixed-capacity circular array queue
 *
 * Operations: Enqueue O(1), Dequeue O(1), GetFront/GetRear O(1)
 */

using System;

class CircularQueue {
    private int[] arr;
    private int front;
    private int rear;
    private int count;
    private int capacity;

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        arr   = new int[capacity];
        front = 0;
        rear  = -1;
        count = 0;
    }

    public bool IsEmpty() => count == 0;
    public bool IsFull()  => count == capacity;
    public int  Size()    => count;

    public void Enqueue(int value) {
        if (IsFull()) {
            Console.WriteLine($"Queue is full! Cannot enqueue {value}");
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    public int Dequeue() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    public int GetFront() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        return arr[front];
    }

    public int GetRear() {
        if (IsEmpty()) throw new InvalidOperationException("Queue is empty");
        return arr[rear];
    }

    static void Main() {
        CircularQueue cq = new CircularQueue(5);

        cq.Enqueue(10);
        cq.Enqueue(20);
        cq.Enqueue(30);
        cq.Enqueue(40);
        cq.Enqueue(50);

        Console.WriteLine($"Front: {cq.GetFront()}, Rear: {cq.GetRear()}");
        Console.WriteLine($"Dequeue: {cq.Dequeue()}");
        Console.WriteLine($"Dequeue: {cq.Dequeue()}");

        // Wrap-around test
        cq.Enqueue(60);
        cq.Enqueue(70);
        Console.WriteLine($"After wrap — Front: {cq.GetFront()}, Rear: {cq.GetRear()}");
    }
}
