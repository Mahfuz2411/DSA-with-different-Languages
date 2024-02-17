#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
	for(int i=1; i<n; i++) {
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
  cout << "Input size of the array: ";
  int n;    cin >> n;
  int arr[n];   

  cout << "Input the array: ";
  for(int i=0; i<n; i++) cin >> arr[i];
  
  cout << "Your array before sorting: [ ";
  for(int i=0; i<n; i++) cout << arr[i] << ' '; 
  cout << "]\n";

  // Calling the sorting function here
  insertionSort(arr, n);  

  cout << "Your array after sorting: [ ";
  for(int i=0; i<n; i++) cout << arr[i] << ' '; 
  cout << "]\n";
  return 0;
}
