"""
Deque - double-ended queue educational implementation

Supports push_front, push_back, pop_front, pop_back, peek_front, peek_back

Complexity: operations O(1) using collections.deque internally
"""

from collections import deque


class Deque:
    def __init__(self):
        self._dq = deque()

    def push_front(self, value):
        self._dq.appendleft(value)

    def push_back(self, value):
        self._dq.append(value)

    def pop_front(self):
        if not self._dq:
            raise IndexError("pop from an empty deque")
        return self._dq.popleft()

    def pop_back(self):
        if not self._dq:
            raise IndexError("pop from an empty deque")
        return self._dq.pop()

    def peek_front(self):
        if not self._dq:
            raise IndexError("peek from empty deque")
        return self._dq[0]

    def peek_back(self):
        if not self._dq:
            raise IndexError("peek from empty deque")
        return self._dq[-1]

    def is_empty(self):
        return len(self._dq) == 0

    def size(self):
        return len(self._dq)


if __name__ == "__main__":
    d = Deque()
    d.push_back(1)
    d.push_front(0)
    d.push_back(2)
    print("Front:", d.peek_front(), "Back:", d.peek_back())
    print("Pop front ->", d.pop_front())
    print("Pop back ->", d.pop_back())
    print("Empty?", d.is_empty())
