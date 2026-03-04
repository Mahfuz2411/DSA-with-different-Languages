# Circular Queue

A **Circular Queue** (also called a Ring Buffer) solves the space wastage problem of a simple queue. When the rear reaches the end of the array, it **wraps around** to the beginning using modulo arithmetic — as long as there is free space at the front.

```
 Index:  0    1    2    3    4
       [ 30 | 40 | __ | 10 | 20 ]
               ↑              ↑
             rear           front

  rear = (rear + 1) % capacity
```

---

## How it works

- Uses a **fixed-size array** with `front`, `rear`, and `count` trackers.
- `enqueue`: move `rear` forward with `(rear + 1) % capacity`, write value.
- `dequeue`: read from `front`, move `front` forward with `(front + 1) % capacity`.
- The queue is **full** when `count == capacity`; **empty** when `count == 0`.

---

## Complexity

| Operation  | Time  | Space |
|------------|-------|-------|
| enqueue    | O(1)  | O(1)  |
| dequeue    | O(1)  | O(1)  |
| front/rear | O(1)  | O(1)  |
| isEmpty/isFull | O(1) | O(1) |

> Space: **O(n)** — fixed capacity allocated upfront.

---

## Use Cases

- OS CPU scheduling (round-robin)
- Audio/video streaming buffers (ring buffers)
- Network packet buffers
- Circular log buffers (overwrite oldest when full)

---

## Pros & Cons

| Pros | Cons |
|------|------|
| No space wastage | Fixed capacity — cannot grow dynamically |
| All operations O(1) | Slightly more complex pointer logic |
| Memory efficient | Must track count or use flag for full/empty |

---

## Implementations

| Language   | File |
|------------|------|
| C          | `C/CircularQueue.c` |
| C++        | `C++/CircularQueue.cc` |
| Java       | `Java/CircularQueue.java` |
| JavaScript | `JavaScript/CircularQueue.js` |
| Python     | `Python/CircularQueue.py` |
| C#         | `C#/CircularQueue.cs` |
