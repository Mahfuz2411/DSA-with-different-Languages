/*
 * Deque - Double-ended queue backed by LinkedList
 *
 * Operations: PushFront/PushBack O(1), PopFront/PopBack O(1), Peek O(1)
 */

using System;
using System.Collections.Generic;

class Deque {
    private LinkedList<int> list;

    public Deque() {
        list = new LinkedList<int>();
    }

    public void PushFront(int value) { list.AddFirst(value); }
    public void PushBack(int value)  { list.AddLast(value); }

    public int PopFront() {
        if (IsEmpty()) throw new InvalidOperationException("Deque is empty");
        int val = list.First.Value;
        list.RemoveFirst();
        return val;
    }

    public int PopBack() {
        if (IsEmpty()) throw new InvalidOperationException("Deque is empty");
        int val = list.Last.Value;
        list.RemoveLast();
        return val;
    }

    public int PeekFront() {
        if (IsEmpty()) throw new InvalidOperationException("Deque is empty");
        return list.First.Value;
    }

    public int PeekBack() {
        if (IsEmpty()) throw new InvalidOperationException("Deque is empty");
        return list.Last.Value;
    }

    public bool IsEmpty() => list.Count == 0;
    public int  Size()    => list.Count;

    static void Main() {
        Deque d = new Deque();

        d.PushBack(1);
        d.PushFront(0);
        d.PushBack(2);

        Console.WriteLine($"Front: {d.PeekFront()}, Back: {d.PeekBack()}");
        Console.WriteLine($"Pop front: {d.PopFront()}");
        Console.WriteLine($"Pop back: {d.PopBack()}");
        Console.WriteLine($"Remaining front: {d.PeekFront()}");
    }
}
