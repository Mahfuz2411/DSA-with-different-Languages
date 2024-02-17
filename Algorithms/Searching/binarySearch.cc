#include<bits/stdc++.h>
using namespace std;

int binarySearchRecursive(vector <int>&v, int b, int e, int key) {
  if(b<e) {
    int m = (b+e)/2;

    if(v[m]==key) return m;
    else if(key<v[m]) return binarySearchRecursive(v, b, m-1, key);
    else return binarySearchRecursive(v, m+1, e, key);
  }
  if(v[b]==key) return b;
  return -1;
}

int binarySearchIterative(vector <int>&v, int key) {
  int left = 0;
  int right = v.size()-1;
  while(left<right) {
    int mid = (left+right)/2;
    if(v[mid]==key) return mid;

    else if(key < v[mid]) right=mid-1;
    else left=mid+1; 
  }
  if(v[left]==key) return left;
  return -1;
}

int main(int argc, char const *argv[]) {
  // array should be sorted
  // test array!! You can take Input from user!
  vector <int> v = {2, 3, 5, 7, 8, 9, 9, 11};  


  // It will return index of the element if exist, -1 otherwise
  // cout << binarySearchRecursive(v, 0, v.size()-1, 9) << endl;
  // cout << binarySearchRecursive(v, 0, v.size()-1, 1) << endl;
  // cout << binarySearchRecursive(v, 0, v.size()-1, 16) << endl;
  // cout << binarySearchRecursive(v, 0, v.size()-1, 6) << endl;


  cout << binarySearchIterative(v, 5) << endl;
  cout << binarySearchIterative(v, 1) << endl;
  cout << binarySearchIterative(v, 16) << endl;
  cout << binarySearchIterative(v, 6) << endl;

  return 0;
}
