using System;
using System.Collections.Generic;

class Program {
  static int BinarySearchRecursive(List<int> arr, int b, int e, int key) {
    if (b < e) {
      int m = (b + e) / 2;

      if (arr[m] == key)
        return m;
      else if (key < arr[m])
        return BinarySearchRecursive(arr, b, m - 1, key);
      else
        return BinarySearchRecursive(arr, m + 1, e, key);
    }
    if (arr[b] == key)
      return b;
    return -1;
  }

  static int BinarySearchIterative(List<int> arr, int key) {
    int left = 0;
    int right = arr.Count - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (arr[mid] == key)
        return mid;
      else if (key < arr[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    if (arr[left] == key)
      return left;
    return -1;
  }

  static void Main(string[] args){
    List<int> arr = new List<int> { 2, 3, 5, 7, 8, 9, 9, 11 };

    Console.WriteLine(BinarySearchIterative(arr, 5));
    Console.WriteLine(BinarySearchIterative(arr, 1));
    Console.WriteLine(BinarySearchIterative(arr, 16));
    Console.WriteLine(BinarySearchIterative(arr, 6));
  }
}
