#include <bits/stdc++.h>
using namespace std;


struct Qsort{
    void quickSort(int [], int, int);
private:
    int partition(int [], int, int);
};

void Qsort::quickSort(int A[], int b, int e) {
    if (b<e) {
        int p = partition(A, b, e);
        quickSort(A, b, p-1);
        quickSort(A, p+1, e);
    }
}

int Qsort::partition(int A[], int b, int e) {
    int x = A[e];
    int i= b-1;
    for(int j=b; j<e; j++) {
        if(A[j]<=x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[e]);
    return i+1;
}


int main(int argc, char const *argv[]) {
  int arr[] = {9, 5, 1, 4, 3};             // test array
  Qsort qsort;                             // Object creation
  qsort.quickSort(arr, 0, 4);              // parameters: array, starting index, ending index
  for(int i=0; i<5; i++) {
      cout<<arr[i]<<' ';  
  }
  cout<<endl;
  return 0;
}