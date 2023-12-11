# What is QuickSort:
    QuickSort is a sorting algorithm that follows the divide-and-conquer paradigm. It was developed by Tony Hoare in 1960. QuickSort is widely used and is known for its efficiency and simplicity. It is an in-place, comparison-based algorithm that sorts an array or list by partitioning it into smaller sub-arrays and recursively sorting those sub-arrays.


# How QuickSort Works:

  ## Partitioning:
    Choose a "pivot" element from the array.
    Rearrange the elements of the array so that all elements smaller than the pivot are on its left, and all elements larger are on its right.
    The pivot is now in its final sorted position.
    Recursion:
    Recursively apply the same process to the sub-arrays on the left and right of the pivot.
    Continue this process until the base case is reached (sub-arrays of size 1 or 0, which are already sorted).


# Complexity of QuickSort:

  ## Time Complexity:
  
    Average Case: 
    O(n log n) - This is the average time complexity when the pivot selection and partitioning are balanced.

    Worst Case: 
    O(n^2) - This occurs when the pivot selection consistently results in poorly balanced partitions.
    
    Space Complexity:
    O(log n) - In-place sorting, but the recursion stack consumes space.


# Why/When to Use QuickSort:

    When average case performance is critical, as QuickSort performs well on average.
    For sorting large datasets where the efficient average-case performance outweighs the less common worst-case scenario.
    When an in-place sorting algorithm is desired to conserve memory.