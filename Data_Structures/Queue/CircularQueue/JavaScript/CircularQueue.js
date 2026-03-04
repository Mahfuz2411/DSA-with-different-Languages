/*
 * CircularQueue - Fixed-capacity circular array queue
 *
 * Operations: enqueue O(1), dequeue O(1), getFront/getRear O(1)
 */

class CircularQueue {
    constructor(capacity) {
        this._arr   = new Array(capacity).fill(null);
        this._cap   = capacity;
        this._front = 0;
        this._rear  = -1;
        this._count = 0;
    }

    isEmpty() { return this._count === 0; }
    isFull()  { return this._count === this._cap; }
    size()    { return this._count; }

    enqueue(value) {
        if (this.isFull()) throw new Error("Queue is full");
        this._rear = (this._rear + 1) % this._cap;
        this._arr[this._rear] = value;
        this._count++;
    }

    dequeue() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        const val = this._arr[this._front];
        this._arr[this._front] = null;
        this._front = (this._front + 1) % this._cap;
        this._count--;
        return val;
    }

    getFront() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        return this._arr[this._front];
    }

    getRear() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        return this._arr[this._rear];
    }
}

const cq = new CircularQueue(5);
cq.enqueue(10);
cq.enqueue(20);
cq.enqueue(30);
cq.enqueue(40);
cq.enqueue(50);

console.log("Front:", cq.getFront(), "Rear:", cq.getRear());
console.log("Dequeue:", cq.dequeue());
console.log("Dequeue:", cq.dequeue());

// Wrap-around test
cq.enqueue(60);
cq.enqueue(70);
console.log("After wrap — Front:", cq.getFront(), "Rear:", cq.getRear());
