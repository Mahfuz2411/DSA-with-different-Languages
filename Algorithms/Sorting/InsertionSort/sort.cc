#include <bits/stdc++.h>
using namespace std;

void Sort(int arr[]) {
    for(int i=1; i<5; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char const *argv[]) {
  int arr[] = {9, 5, 1, 4, 3};   
  Sort(arr);  
  for(int i=0; i<5; i++) {
      cout<<arr[i]<<' ';  
  }
  cout<<endl;
  return 0;
}
