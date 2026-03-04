/*
 * SimpleQueue - Basic FIFO queue
 *
 * Operations: enqueue O(1), dequeue O(n), front/rear O(1)
 */

public class SimpleQueue {
    private int[] data;
    private int count;
    private int capacity;

    public SimpleQueue(int capacity) {
        this.capacity = capacity;
        this.data = new int[capacity];
        this.count = 0;
    }

    public void enqueue(int value) {
        if (count == capacity) {
            System.out.println("Queue overflow!");
            return;
        }
        data[count++] = value;
    }

    public int dequeue() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        int val = data[0];
        for (int i = 0; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
        return val;
    }

    public int front() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        return data[0];
    }

    public int rear() {
        if (isEmpty()) throw new RuntimeException("Queue is empty");
        return data[count - 1];
    }

    public boolean isEmpty() { return count == 0; }
    public int size()        { return count; }

    public static void main(String[] args) {
        SimpleQueue q = new SimpleQueue(10);

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        System.out.println("Front: " + q.front() + ", Rear: " + q.rear());
        System.out.println("Dequeue: " + q.dequeue());
        System.out.println("Front after dequeue: " + q.front());
    }
}
