/*
 * SimpleQueue - Basic FIFO queue
 *
 * Operations: enqueue O(1), dequeue O(n), front/rear O(1)
 */

class SimpleQueue {
    constructor() {
        this._data = [];
    }

    enqueue(value) {
        this._data.push(value);
    }

    dequeue() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        return this._data.shift();
    }

    front() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        return this._data[0];
    }

    rear() {
        if (this.isEmpty()) throw new Error("Queue is empty");
        return this._data[this._data.length - 1];
    }

    isEmpty() { return this._data.length === 0; }
    size()    { return this._data.length; }
}

const q = new SimpleQueue();
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);

console.log("Front:", q.front(), "Rear:", q.rear());
console.log("Dequeue:", q.dequeue());
console.log("Front after dequeue:", q.front());
