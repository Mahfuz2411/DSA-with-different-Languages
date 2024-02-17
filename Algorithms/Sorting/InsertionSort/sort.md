# Insertion Sort

## What is Insertion Sort?
Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It iterates through the input elements, removing one element at a time and then finding its correct position in the sorted list. It repeats this process until no input elements remain. 

## Why Use Insertion Sort?
- **Simplicity:** Insertion sort is easy to understand and implement.
- **Efficiency for Small Data Sets:** It performs well for small data sets or nearly sorted arrays.
- **Adaptive:** It's adaptive, meaning it can efficiently handle data sets that are already partially sorted.
- **In-Place:** It sorts the array in-place, requiring only a constant amount of additional memory space.

## Time Complexity
- **Best Case:** O(n) when the array is already sorted.
- **Worst Case:** O(n^2) when the array is sorted in reverse order.
- **Average Case:** O(n^2).

## Pseudocode
```plaintext
function insertionSort(arr)
    for i = 1 to length(arr) - 1 do
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key do
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
```