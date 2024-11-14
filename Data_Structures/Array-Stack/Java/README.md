```java
/**
 * ** Prerequisite to understand this code
 *  -> Object Oriented Programming
 */

// Class representing a dynamic array-based stack
class list {
  // Instance variables: arr is the array holding stack elements, 
  // s is the size of the stack, and len is the capacity of the array.
  int[] arr;
  int s, len;

  // Constructor to initialize the stack.
  list() {
    s = 0;   // Initially, the stack is empty (size = 0).
    len = 1; // Start with an initial capacity of 1.
    arr = new int[len];  // Create the array with initial capacity.
  }

  // Method to push an element onto the stack.
  void push(int x) {
    // If the stack is full (size == capacity), resize the array.
    if (s == len) resize();
    // Place the new element at the top of the stack (position 's').
    arr[s] = x;
    // Increment the stack size.
    s++;
  }

  // Method to pop an element from the stack.
  int pop() {
    // Store the top element before removing it.
    int temp = arr[s - 1];
    // Decrement the size of the stack (remove the top element).
    s--;
    // If the stack is now one-third full, resize the array to save space.
    if (len / 3 >= s) resize();
    // Return the removed element.
    return temp;
  }

  // Method to print the current elements in the stack.
  void print() {
    // Print the opening square bracket for the stack.
    System.out.print("[ ");
    // Print all the elements in the stack.
    for (int i = 0; i < s; i++) System.out.print(arr[i] + " ");
    // Print the closing square bracket.
    System.out.println(']');
  }

  // Method to resize the array when the stack is full or under-utilized.
  void resize() {
    // Double the capacity of the array when the stack is full.
    len = s * 2;
    // Create a new array with the new capacity.
    int[] brr = new int[len];
    // Copy all elements from the old array to the new one.
    for (int i = 0; i < s; i++) {
      brr[i] = arr[i];
    }
    // Replace the old array with the new one.
    arr = brr;
  }
}

// Main class to test the stack implementation.
public class stack {
  public static void main(String[] args) {
    // Create an instance of the 'list' class, representing the stack.
    list ob = new list();

    // Push elements onto the stack.
    ob.push(5);
    ob.push(7);
    ob.push(9);

    // Print the stack after pushing elements.
    ob.print();  // Expected output: [ 5 7 9 ]

    // Pop an element from the stack and print it.
    System.out.println(ob.pop());  // Expected output: 9 (the last pushed element)

    // Print the stack after popping an element.
    ob.print();  // Expected output: [ 5 7 ]
  }
}
```