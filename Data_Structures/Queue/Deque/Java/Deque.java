/*
 * Deque - Double-ended queue backed by a doubly-linked list
 *
 * Operations: pushFront/pushBack O(1), popFront/popBack O(1), peek O(1)
 */

public class Deque {
    private java.util.LinkedList<Integer> list;

    public Deque() {
        list = new java.util.LinkedList<>();
    }

    public void pushFront(int value) { list.addFirst(value); }
    public void pushBack(int value)  { list.addLast(value); }

    public int popFront() {
        if (isEmpty()) throw new RuntimeException("Deque is empty");
        return list.removeFirst();
    }

    public int popBack() {
        if (isEmpty()) throw new RuntimeException("Deque is empty");
        return list.removeLast();
    }

    public int peekFront() {
        if (isEmpty()) throw new RuntimeException("Deque is empty");
        return list.getFirst();
    }

    public int peekBack() {
        if (isEmpty()) throw new RuntimeException("Deque is empty");
        return list.getLast();
    }

    public boolean isEmpty() { return list.isEmpty(); }
    public int size()        { return list.size(); }

    public static void main(String[] args) {
        Deque d = new Deque();

        d.pushBack(1);
        d.pushFront(0);
        d.pushBack(2);

        System.out.println("Front: " + d.peekFront() + ", Back: " + d.peekBack());
        System.out.println("Pop front: " + d.popFront());
        System.out.println("Pop back: " + d.popBack());
        System.out.println("Remaining front: " + d.peekFront());
    }
}
