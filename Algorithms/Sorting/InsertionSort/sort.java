package Algorithms.Sorting.InsertionSort;

import java.util.*;

public class sort {
  public static void insertionSort(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      int key = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Input size of the array: ");
    int n = sc.nextInt();
    int[] arr = new int[n];

    System.out.print("Input the array: ");
    for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();

    System.out.print("Your array before sorting: [ ");
    for (int value : arr)
      System.out.print(value + " ");
    System.out.println("]");

    insertionSort(arr);

    System.out.print("Your array after sorting: [ ");
    for (int value : arr)
      System.out.print(value + " ");
    System.out.println("]");

    sc.close();
  }
}
