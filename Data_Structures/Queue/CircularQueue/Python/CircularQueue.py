"""
CircularQueue - fixed-capacity circular queue using list

Operations:
- enqueue(value) : raises OverflowError if full
- dequeue() : raises IndexError if empty
- get_front(), get_rear(), is_empty(), is_full(), size(), clear()

Complexity: all operations O(1)
"""


class CircularQueue:
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("capacity must be > 0")
        self._arr = [None] * capacity
        self._cap = capacity
        self._front = 0
        self._rear = -1
        self._count = 0

    def enqueue(self, value):
        if self.is_full():
            raise OverflowError("Queue is full")
        self._rear = (self._rear + 1) % self._cap
        self._arr[self._rear] = value
        self._count += 1

    def dequeue(self):
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        val = self._arr[self._front]
        self._arr[self._front] = None
        self._front = (self._front + 1) % self._cap
        self._count -= 1
        return val

    def get_front(self):
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self._arr[self._front]

    def get_rear(self):
        if self.is_empty():
            raise IndexError("rear from empty queue")
        return self._arr[self._rear]

    def is_empty(self):
        return self._count == 0

    def is_full(self):
        return self._count == self._cap

    def size(self):
        return self._count

    def clear(self):
        self._arr = [None] * self._cap
        self._front = 0
        self._rear = -1
        self._count = 0


if __name__ == "__main__":
    cq = CircularQueue(5)
    for x in [1, 2, 3, 4, 5]:
        cq.enqueue(x)
    print("Front:", cq.get_front(), "Rear:", cq.get_rear())
    try:
        cq.enqueue(6)
    except OverflowError as e:
        print("Expected overflow:", e)
    print("Dequeue ->", cq.dequeue())
    cq.enqueue(6)
    print("After wrap, elements:", [cq.dequeue() for _ in range(cq.size())])
