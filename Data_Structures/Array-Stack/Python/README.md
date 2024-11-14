```py
# Define the Stack class
class Stack:
    # Constructor to initialize the stack
    def __init__(self):
        # Initialize an empty list to represent the stack
        self.arr = []
        # Initialize size to 0, representing an empty stack
        self.size = 0
        
    # Overloaded constructor that initializes the stack with one element
    def __init__(self, x):
        # Initialize the list with one element, x
        self.arr = []
        self.arr.append(x)  # Add x to the stack
        self.size = 1  # Set size to 1, as we have one item in the stack
        
    # Method to add an element to the stack
    def push_back(self, x):
        # Append the element x to the end of the stack (the list)
        self.arr.append(x)
        # Increase the size of the stack by 1
        self.size += 1
        
    # Method to remove and return the last element from the stack
    def pop_back(self):
        # Check if the stack is empty (size is 0 or less)
        if self.size <= 0:
            # If the stack is empty, return -1 to indicate an error
            return -1
        else:
            # Store the last element of the stack in a temporary variable
            temp = self.arr[-1]
            # Remove the last element from the stack
            self.arr.pop()
            # Decrease the size of the stack by 1
            self.size -= 1
            # Return the value that was popped
            return temp
        
    # Method to print the elements in the stack
    def Print(self):
        # Print the list (representing the stack) to show the current stack contents
        print(self.arr)


# Create an instance of the Stack class with an initial value of 5
ob = Stack(5)
# Print the current stack
ob.Print()

# Push several values onto the stack
ob.push_back(10)
ob.push_back(100)
ob.push_back(50)
ob.push_back(30)

# Print the stack after pushing the new values
ob.Print()

# Pop elements from the stack and print them
print(ob.pop_back())  # Expected output: 30 (last pushed element)
print(ob.pop_back())  # Expected output: 50
print(ob.pop_back())  # Expected output: 100
print(ob.pop_back())  # Expected output: 10

# Try popping again when the stack is empty, expected output: -1
print(ob.pop_back())  # Expected output: -1

# Print the stack after popping all elements
ob.Print()  # Expected output: [] (empty stack)

```