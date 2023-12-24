# Binary Search Tree (BST) (Not Completed)

## Overview

A Binary Search Tree (BST) is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. The key property of a BST is that the key values in the left subtree are less than the key value in the root, and the key values in the right subtree are greater than the key value in the root.

## Operations

BST supports the following basic operations:
- **Insertion:** Adding a new key to the tree.
- **Deletion:** Removing a key from the tree.
- **Search:** Finding the presence of a key in the tree.

## Properties

- **Ordered Structure:** The elements in a BST are stored in a way that maintains the order among them, making search operations efficient.
- **Fast Search:** Searching for a key in a BST has an average time complexity of O(log n), where n is the number of nodes in the tree.

## Pros

1. **Efficient Search:** Binary Search Trees provide fast search operations due to their ordered structure.
2. **Easy to Implement:** The basic operations of insertion, deletion, and search are relatively straightforward to implement.
3. **In-order Traversal:** In-order traversal of a BST results in a sorted sequence of elements.

## Cons

1. **Unbalanced Trees:** If elements are inserted in sorted order, or if the tree is not properly balanced, the BST may degenerate into a linked list, leading to inefficient search times.
2. **Sensitive to Input Order:** The efficiency of a BST heavily depends on the order in which elements are inserted. Poorly balanced trees can lead to suboptimal performance.
3. **No O(1) Operations:** Unlike hash tables, BST operations don't guarantee constant time complexity, making them less suitable for scenarios where O(1) operations are crucial.

## Time Complexity

- **Insertion:** O(log n) on average, O(n) in the worst case.
- **Deletion:** O(log n) on average, O(n) in the worst case.
- **Search:** O(log n) on average, O(n) in the worst case.

## Conclusion

Binary Search Trees are a versatile data structure with efficient search operations when properly balanced. However, their performance can degrade in certain scenarios, making them less suitable for applications where the order of input data is unpredictable or where constant time complexity is critical.
