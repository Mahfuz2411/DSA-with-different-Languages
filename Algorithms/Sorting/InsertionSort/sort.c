#include <stdio.h>

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
  printf("Input size of the array: ");
  int n;    scanf("%d", &n);
  int arr[n];   

  printf("Input the array: ");
  for(int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }
  
  printf("Your array before sorting: [ ");
  for(int i=0; i<n; i++) {
      printf("%d ",arr[i]); 
  }
  printf("]\n");

  // Calling the sorting function here
  insertionSort(arr, n);  

  printf("Your array after sorting: [ ");
  for(int i=0; i<n; i++) {
      printf("%d ",arr[i]); 
  }
  printf("]\n");
  return 0;
}