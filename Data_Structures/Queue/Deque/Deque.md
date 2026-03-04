# Deque (Double-Ended Queue)

A **Deque** (pronounced *deck*) is a generalised queue that allows **insertion and removal from both ends** — front and back. It can behave as both a queue (FIFO) and a stack (LIFO) depending on how it is used.

```
pushFront ──►  [ 10 | 20 | 30 | 40 ]  ◄── pushBack
popFront  ◄──                          ──► popBack
```

---

## How it works

- Backed by a **circular array** (C implementation) or **doubly linked list** (Java, C# implementations).
- `pushFront`: move front pointer backward; `pushBack`: move rear pointer forward.
- `popFront` / `popBack`: read value and move corresponding pointer.
- Python's `collections.deque` and C++'s `std::deque` are standard-library backed.

---

## Complexity

| Operation          | Time  | Space |
|--------------------|-------|-------|
| pushFront/pushBack | O(1)  | O(1)  |
| popFront/popBack   | O(1)  | O(1)  |
| peekFront/peekBack | O(1)  | O(1)  |
| isEmpty            | O(1)  | O(1)  |

> Space: **O(n)**.

---

## Use Cases

- Sliding window problems (e.g., maximum in a window)
- Implementing both stack and queue with a single structure
- Browser history navigation (back and forward)
- Undo/redo functionality
- Palindrome checking

---

## Pros & Cons

| Pros | Cons |
|------|------|
| Flexible — works as queue or stack | Slightly more complex than a simple queue |
| All operations O(1) | Circular array version has fixed capacity |
| Useful for sliding window algorithms | Linked-list version has pointer overhead |

---

## Implementations

| Language   | File |
|------------|------|
| C          | `C/Deque.c` |
| C++        | `C++/deque.cc` |
| Java       | `Java/Deque.java` |
| JavaScript | `JavaScript/Deque.js` |
| Python     | `Python/Deque.py` |
| C#         | `C#/Deque.cs` |
