"""
SimpleQueue - basic FIFO queue implementation (educational)

Operations:
- enqueue(value)
- dequeue()
- front(), rear(), is_empty(), size(), clear()

Complexity: enqueue O(1), dequeue O(1) using collections.deque internally.
"""
from collections import deque


class SimpleQueue:
    def __init__(self):
        self._dq = deque()

    def enqueue(self, value):
        self._dq.append(value)

    def dequeue(self):
        if not self._dq:
            raise IndexError("dequeue from empty queue")
        return self._dq.popleft()

    def front(self):
        if not self._dq:
            raise IndexError("front from empty queue")
        return self._dq[0]

    def rear(self):
        if not self._dq:
            raise IndexError("rear from empty queue")
        return self._dq[-1]

    def is_empty(self):
        return len(self._dq) == 0

    def size(self):
        return len(self._dq)

    def clear(self):
        self._dq.clear()


if __name__ == "__main__":
    q = SimpleQueue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    print("Queue size:", q.size())
    print("Front:", q.front(), "Rear:", q.rear())
    print("Dequeue ->", q.dequeue())
    print("After dequeue, front:", q.front())
    q.clear()
    print("Empty?", q.is_empty())
