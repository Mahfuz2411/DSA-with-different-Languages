function binarySearchRecursive(arr, b, e, key) {
  if (b < e) {
    let m = Math.floor((b + e) / 2);

    if (arr[m] === key) return m;
    else if (key < arr[m]) return binarySearchRecursive(arr, b, m - 1, key);
    else return binarySearchRecursive(arr, m + 1, e, key);
  }
  if (arr[b] === key) return b;
  return -1;
}

function binarySearchIterative(arr, key) {
  let left = 0;
  let right = arr.length - 1;
  while (left < right) {
    let mid = Math.floor((left + right) / 2);
    if (arr[mid] === key) return mid;
    else if (key < arr[mid]) right = mid - 1;
    else left = mid + 1;
  }
  if (arr[left] === key) return left;
  return -1;
}

let arr = [2, 3, 5, 7, 8, 9, 9, 11];

console.log(binarySearchIterative(arr, 5));
console.log(binarySearchIterative(arr, 1));
console.log(binarySearchIterative(arr, 16));
console.log(binarySearchIterative(arr, 6));
