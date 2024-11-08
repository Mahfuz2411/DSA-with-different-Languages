import java.util.*;

public class binarySearch {
  static int binarySearchRecursive(List<Integer> arr, int b, int e, int key) {
    if (b < e) {
      int m = (b + e) / 2;

      if (arr.get(m).equals(key))
        return m;
      else if (key < arr.get(m))
        return binarySearchRecursive(arr, b, m - 1, key);
      else
        return binarySearchRecursive(arr, m + 1, e, key);
    }
    if (arr.get(b).equals(key))
      return b;
    return -1;
  }

  static int binarySearchIterative(List<Integer> arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (arr.get(mid).equals(key))
        return mid;
      else if (key < arr.get(mid))
        right = mid - 1;
      else
        left = mid + 1;
    }
    if (arr.get(left).equals(key))
      return left;
    return -1;
  }

  public static void main(String[] args) {
    List<Integer> arr = new ArrayList<>(Arrays.asList(2, 3, 5, 7, 8, 9, 9, 11));

    System.out.println(binarySearchIterative(arr, 5));
    System.out.println(binarySearchIterative(arr, 1));
    System.out.println(binarySearchIterative(arr, 16));
    System.out.println(binarySearchIterative(arr, 6));
  }
}
