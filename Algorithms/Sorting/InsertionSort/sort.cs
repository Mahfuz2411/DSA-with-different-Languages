using System;

class Program {
  static void InsertionSort(int[] arr) {
    for (int i = 1; i < arr.Length; i++) {
      int key = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
    }
  }

  static void Main(string[] args) {
    Console.Write("Input size of the array: ");
    int n = int.Parse(Console.ReadLine());
    int[] arr = new int[n];
    Console.Write("Input the array: ");
    string[] input = Console.ReadLine().Split();
    for (int i = 0; i < n; i++) arr[i] = int.Parse(input[i]);

    Console.Write("Your array before sorting: [ ");
    foreach (int value in arr) Console.Write(value + " ");
    Console.WriteLine("]");

    InsertionSort(arr);

    Console.Write("Your array after sorting: [ ");
    foreach (int value in arr) Console.Write(value + " ");
    Console.WriteLine("]");
  }
}
