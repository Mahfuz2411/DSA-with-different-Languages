# Simple Queue

A **Simple Queue** is the most basic form of a queue. It strictly follows **FIFO** (First In, First Out) — elements enter at the rear and leave from the front.

```
enqueue ──►  [ 10 | 20 | 30 | 40 ]  ──► dequeue
            rear                  front
```

---

## How it works

- Internally backed by an **array** (or linked list).
- `enqueue` appends to the end — O(1).
- `dequeue` removes from index 0 and shifts all remaining elements left — O(n).
- Use a **Circular Queue** if you want O(1) dequeue with fixed memory.

---

## Complexity

| Operation  | Time  | Space |
|------------|-------|-------|
| enqueue    | O(1)  | O(1)  |
| dequeue    | O(n)  | O(1)  |
| front/rear | O(1)  | O(1)  |
| isEmpty    | O(1)  | O(1)  |

> Space complexity of the queue itself: **O(n)** where n = number of elements.

---

## Use Cases

- Print spooling / task queues
- BFS traversal
- Request handling in simple servers
- Any situation where ordering must be preserved

---

## Pros & Cons

| Pros | Cons |
|------|------|
| Simple to implement | Dequeue is O(n) due to shifting |
| Easy to understand | Fixed capacity (array-backed) |
| FIFO guaranteed | Front space is wasted after dequeue |

---

## Implementations

| Language   | File |
|------------|------|
| C          | `C/SimpleQueue.c` |
| C++        | `C++/SimpleQueue.cc` |
| Java       | `Java/SimpleQueue.java` |
| JavaScript | `JavaScript/SimpleQueue.js` |
| Python     | `Python/SimpleQueue.py` |
| C#         | `C#/SimpleQueue.cs` |
