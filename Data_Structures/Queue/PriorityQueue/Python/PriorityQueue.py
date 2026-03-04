"""
PriorityQueue - min-heap based priority queue (uses heapq)

API: push(item, priority), pop(), peek(), is_empty(), size()

Complexity: push/pop O(log n)
"""

import heapq


class PriorityQueue:
    def __init__(self):
        self._heap = []  # (priority, count, item)
        self._counter = 0

    def push(self, item, priority=0):
        # lower priority value -> higher priority
        heapq.heappush(self._heap, (priority, self._counter, item))
        self._counter += 1

    def pop(self):
        if not self._heap:
            raise IndexError("pop from empty priority queue")
        return heapq.heappop(self._heap)[2]

    def peek(self):
        if not self._heap:
            raise IndexError("peek from empty priority queue")
        return self._heap[0][2]

    def is_empty(self):
        return len(self._heap) == 0

    def size(self):
        return len(self._heap)


if __name__ == "__main__":
    pq = PriorityQueue()
    pq.push("low", priority=10)
    pq.push("high", priority=1)
    pq.push("medium", priority=5)
    print("Peek:", pq.peek())
    while not pq.is_empty():
        print("Pop:", pq.pop())
