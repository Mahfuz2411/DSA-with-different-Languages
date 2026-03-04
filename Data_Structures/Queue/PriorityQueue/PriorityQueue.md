# Priority Queue

A **Priority Queue** is a queue where each element has an associated **priority**. Elements are dequeued in order of priority, not insertion order. This implementation uses a **min-heap** — the element with the **smallest value** is dequeued first.

```
push(30) push(10) push(50) push(20)

Heap (min at root):
         10
        /  \
       20   50
      /
     30

pop() → 10   pop() → 20   pop() → 30   pop() → 50
```

---

## How it works

- Internally backed by a **binary min-heap** (array representation).
- `push`: append to end, then `heapifyUp` to restore heap property — O(log n).
- `pop`: swap root with last element, remove last, then `heapifyDown` — O(log n).
- `peek`: read root directly — O(1).
- Parent of index `i` → `(i-1)/2`; children → `2i+1`, `2i+2`.

---

## Complexity

| Operation | Time     | Space |
|-----------|----------|-------|
| push      | O(log n) | O(1)  |
| pop       | O(log n) | O(1)  |
| peek      | O(1)     | O(1)  |
| isEmpty   | O(1)     | O(1)  |

> Space: **O(n)**.

---

## Use Cases

- Dijkstra's shortest path algorithm
- A* search algorithm
- CPU / OS task scheduling (by priority)
- Huffman coding (data compression)
- Event-driven simulations
- Finding the k-th smallest/largest element

---

## Pros & Cons

| Pros | Cons |
|------|------|
| Efficient push and pop — O(log n) | Not O(1) like a simple queue |
| Peek is O(1) | Complex heapify logic |
| No need to sort entire collection | Min-heap only — max-heap needs negation or custom comparator |

---

## Implementations

| Language   | File |
|------------|------|
| C          | `C/PriorityQueue.c` |
| C++        | `C++/PriorityQueue.cc` |
| Java       | `Java/PriorityQueue.java` |
| JavaScript | `JavaScript/PriorityQueue.js` |
| Python     | `Python/PriorityQueue.py` |
| C#         | `C#/PriorityQueue.cs` |
