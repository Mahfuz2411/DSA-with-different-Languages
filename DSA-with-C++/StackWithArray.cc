#include <bits/stdc++.h>
using namespace std;

class Stack {
  int* arr;
  int size;
  int len;

public:
  Stack() : size(0), len(1) {
    arr = new int[len]; 
  }

  void resize() {
    len = 2 * size;
    int* brr = new int[len];
    for (int i = 0; i < size; i++) {
      brr[i] = arr[i];
    }
    delete[] arr; 
    arr = brr;
  }

  void push(int x) {
    arr[size] = x;
    size++;
    if (size == len) {
      resize();
    }
  }

  int pop() {
    if (size == 0) {
      return INT_MIN;
    }
    size--;
    if (size <= len / 3) {
      resize();
    }
    return arr[size];
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << endl;
    }
  }
};

int main(int argc, char const* argv[]) {
  Stack obj;
  obj.push(5);
  obj.push(9);
  obj.push(7);
  cout << obj.pop() << endl;
  obj.print();
  return 0;
}

