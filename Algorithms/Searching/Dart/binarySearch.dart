int binarySearchRecursive(List<int> arr, int b, int e, int key) {
  if (b < e) {
    int m = (b + e) ~/ 2;

    if (arr[m] == key)
      return m;
    else if (key < arr[m])
      return binarySearchRecursive(arr, b, m - 1, key);
    else
      return binarySearchRecursive(arr, m + 1, e, key);
  }
  if (arr[b] == key)
    return b;
  return -1;
}

int binarySearchIterative(List<int> arr, int key) {
  int left = 0;
  int right = arr.length - 1;
  while (left < right) {
    int mid = (left + right) ~/ 2;
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

void main() {
  List<int> arr = [2, 3, 5, 7, 8, 9, 9, 11];

  print(binarySearchIterative(arr, 5));
  print(binarySearchIterative(arr, 1));
  print(binarySearchIterative(arr, 16));
  print(binarySearchIterative(arr, 6));
}
