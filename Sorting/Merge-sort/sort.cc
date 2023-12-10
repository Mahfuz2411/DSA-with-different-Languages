#include <bits/stdc++.h>
using namespace std;


struct Msort{
    void MergeSort(int A[], int b, int e) {
        if(b<e){
            int m = (b+e)/2;
            MergeSort(A, b, m);
            MergeSort(A, m+1, e);
            Merge(A, b, m, e);
        }
        for(int i=0; i<5; i++) {
            cout<<A[i]<<' ';  
        }cout<<endl;
    }

private:
    void Merge(int A[], int b, int m, int e) {
        int n1 = m - b + 1;
        int n2 = e - m;
        int L[n1+1], R[n2+1];
        int i, j;
        for(i=0; i<n1; i++) {
            L[i] = A[b+i];
        }
        for(j=0; j<n2; j++) {
            R[j] = A[m + j + 1];
        }
        L[n1] = R[n2] = INT_MAX;
        i = j = 0;
        for(int k=b; k<=e; k++) {
            if(L[i]<=R[j]) A[k] = L[i++];
            else A[k] = R[j++];
        }
    }
};


int main(int argc, char const *argv[]) {
  int arr[] = {9, 5, 1, 4, 3};             // test array
  Msort msort;                             // Object creation
  msort.MergeSort(arr, 0, 4);              // parameters: array, starting index, ending index
  for(int i=0; i<5; i++) {
      cout<<arr[i]<<' ';  
  }
  cout<<endl;
  return 0;
}