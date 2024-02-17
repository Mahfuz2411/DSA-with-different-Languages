function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

let arr = [2, 5, 1, 4, 3, 8, 6, 7]
console.log("Your array before sorting: [ " + arr.join(" ") + " ]");

insertionSort(arr);

console.log("Your array after sorting: [ " + arr.join(" ") + " ]");
