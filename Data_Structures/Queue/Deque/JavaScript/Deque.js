/*
 * Deque - Double-ended queue
 *
 * Operations: pushFront/pushBack O(1)*, popFront/popBack O(1)*, peek O(1)
 * (* amortised; JS Array.unshift/shift are O(n) for large n —
 *    use a doubly-linked list for production use)
 */

class Deque {
    constructor() {
        this._data = [];
    }

    pushFront(value) { this._data.unshift(value); }
    pushBack(value)  { this._data.push(value); }

    popFront() {
        if (this.isEmpty()) throw new Error("Deque is empty");
        return this._data.shift();
    }

    popBack() {
        if (this.isEmpty()) throw new Error("Deque is empty");
        return this._data.pop();
    }

    peekFront() {
        if (this.isEmpty()) throw new Error("Deque is empty");
        return this._data[0];
    }

    peekBack() {
        if (this.isEmpty()) throw new Error("Deque is empty");
        return this._data[this._data.length - 1];
    }

    isEmpty() { return this._data.length === 0; }
    size()    { return this._data.length; }
}

const d = new Deque();
d.pushBack(1);
d.pushFront(0);
d.pushBack(2);

console.log("Front:", d.peekFront(), "Back:", d.peekBack());
console.log("Pop front:", d.popFront());
console.log("Pop back:", d.popBack());
console.log("Remaining front:", d.peekFront());
