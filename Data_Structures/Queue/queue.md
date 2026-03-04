# Queue

A **Queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle — the element inserted first is the one removed first, just like a queue of people waiting in line.

```
  enqueue ──►  [ 10 | 20 | 30 | 40 ]  ──► dequeue
              rear                   front
```

---

## Core Operations

| Operation | Description                          |
|-----------|--------------------------------------|
| enqueue   | Insert an element at the rear        |
| dequeue   | Remove the element from the front    |
| peek/front| View the front element without removing it |
| isEmpty   | Check whether the queue is empty     |

---

## Types of Queue

| Type           | Key Feature                                  | Folder |
|----------------|----------------------------------------------|--------|
| Simple Queue   | Basic FIFO, linear array                     | `SimpleQueue/` |
| Circular Queue | Rear wraps around to reuse freed front slots | `CircularQueue/` |
| Deque          | Insertion & removal allowed at both ends     | `Deque/` |
| Priority Queue | Elements dequeued by priority, not order     | `PriorityQueue/` |

> Each type has its own detailed documentation inside its folder.

---

## When to use a Queue?

- **Task scheduling** — CPU/process scheduling (round-robin)
- **BFS / Level-order traversal** — graph and tree algorithms
- **Print spooling** — managing printer jobs
- **Buffering** — keyboard input, data streams, network packets
- **Undo systems** — command history in editors

---

## Memory representation

Queues can be implemented using:
- **Array** — static size, simple but may waste space (use circular variant to avoid this)
- **Linked list** — dynamic size, no wasted space, slightly more overhead per node

---

## Languages implemented

C · C++ · Java · JavaScript · Python · C#
