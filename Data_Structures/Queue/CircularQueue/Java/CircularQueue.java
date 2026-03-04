/*
 * CircularQueue - Fixed-capacity circular array queue
 *
 * Operations: enqueue O(1), dequeue O(1), getFront/getRear O(1)
 */

public class CircularQueue {
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

    public boolean isEmpty() { return count == 0; }
    public boolean isFull()  { return count == capacity; }
    public int size()        { return count; }

    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full! Cannot enqueue " + value);
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    public int dequeue() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    public int getFront() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        return arr[front];
    }

    public int getRear() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        return arr[rear];
    }

    public static void main(String[] args) {
        CircularQueue cq = new CircularQueue(5);

        cq.enqueue(10);
        cq.enqueue(20);
        cq.enqueue(30);
        cq.enqueue(40);
        cq.enqueue(50);

        System.out.println("Front: " + cq.getFront() + ", Rear: " + cq.getRear());
        System.out.println("Dequeue: " + cq.dequeue());
        System.out.println("Dequeue: " + cq.dequeue());

        // Wrap-around test
        cq.enqueue(60);
        cq.enqueue(70);
        System.out.println("Front: " + cq.getFront() + ", Rear: " + cq.getRear());
    }
}
