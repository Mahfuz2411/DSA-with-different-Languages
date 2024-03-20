def binary_search_recursive(arr, b, e, key):
  if b < e:
    m = (b + e) // 2

    if arr[m] == key:
      return m
    elif key < arr[m]:
      return binary_search_recursive(arr, b, m - 1, key)
    else:
      return binary_search_recursive(arr, m + 1, e, key)

  if arr[b] == key:
    return b
  return -1

def binary_search_iterative(arr, key):
  left = 0
  right = len(arr) - 1
  while left < right:
    mid = (left + right) // 2
    if arr[mid] == key:
      return mid
    elif key < arr[mid]:
      right = mid - 1
    else:
      left = mid + 1

  if arr[left] == key:
    return left
  return -1

# Test array
arr = [2, 3, 5, 7, 8, 9, 9, 11]

print(binary_search_recursive(arr,0, len(arr), 5))
print(binary_search_iterative(arr, 1))
print(binary_search_iterative(arr, 16))
print(binary_search_iterative(arr, 6))
