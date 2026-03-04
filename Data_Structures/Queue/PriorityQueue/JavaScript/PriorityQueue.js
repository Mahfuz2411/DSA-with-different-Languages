/*
 * PriorityQueue - Min-heap based priority queue
 *
 * Operations: push O(log n), pop O(log n), peek O(1)
 * Smallest value has highest priority.
 */

class PriorityQueue {
    constructor() {
        this._heap = [];
    }

    isEmpty() { return this._heap.length === 0; }
    size()    { return this._heap.length; }

    _swap(i, j) {
        [this._heap[i], this._heap[j]] = [this._heap[j], this._heap[i]];
    }

    _heapifyUp(i) {
        while (i > 0) {
            const parent = Math.floor((i - 1) / 2);
            if (this._heap[i] < this._heap[parent]) {
                this._swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }

    _heapifyDown(i) {
        const n = this._heap.length;
        let smallest = i;
        const left  = 2 * i + 1;
        const right = 2 * i + 2;
        if (left  < n && this._heap[left]  < this._heap[smallest]) smallest = left;
        if (right < n && this._heap[right] < this._heap[smallest]) smallest = right;
        if (smallest !== i) {
            this._swap(i, smallest);
            this._heapifyDown(smallest);
        }
    }

    push(value) {
        this._heap.push(value);
        this._heapifyUp(this._heap.length - 1);
    }

    pop() {
        if (this.isEmpty()) throw new Error("Priority queue is empty");
        if (this.size() === 1) return this._heap.pop();
        const min = this._heap[0];
        this._heap[0] = this._heap.pop();
        this._heapifyDown(0);
        return min;
    }

    peek() {
        if (this.isEmpty()) throw new Error("Priority queue is empty");
        return this._heap[0];
    }
}

const pq = new PriorityQueue();
pq.push(30);
pq.push(10);
pq.push(50);
pq.push(20);

console.log("Peek (min):", pq.peek());
while (!pq.isEmpty()) {
    console.log("Pop:", pq.pop());
}
