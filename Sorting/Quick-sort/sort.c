#include <stdio.h>

// Function to swap two integer values
void swap(int *x, int *y) {
  int temp = *y;                      // Store the value pointed to by y in a temporary variable
  *y = *x;                            // Assign the value pointed to by x to y
  *x = temp;                          // Assign the temporary variable value to x
}

// Function to partition the array and return the pivot index
int partition(int A[], int b, int e) {
  int x = A[e];                       // Choose the last element as the pivot
  int i = b - 1;                      // Initialize the index of the smaller element

  // Iterate through the array to partition elements around the pivot
  for(int j = b; j < e; j++) {
      if(A[j] <= x) {
          i++;
          // Swap the current element with the element at the smaller index
          swap(&A[i], &A[j]);
      }
  }

  // Swap the pivot element with the element at the next index after the smaller elements
  swap(&A[i + 1], &A[e]);
  return i + 1;                       // Return the index of the pivot element
}

// Recursive function to perform quicksort on the array
void quickSort(int A[], int b, int e) {
  if (b < e) {
      int p = partition(A, b, e);     // Get the pivot index
      quickSort(A, b, p - 1);         // Recursively sort elements before the pivot
      quickSort(A, p + 1, e);         // Recursively sort elements after the pivot
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {9, 5, 1, 4, 3};       // Test array
  // Call the quickSort function with array and indices
  quickSort(arr, 0, 4);              // Parameters: array, starting index, ending index
  for(int i = 0; i < 5; i++) {
      printf("%d ", arr[i]);         // Print the sorted array
  }
  printf("\n");
  return 0;
}
