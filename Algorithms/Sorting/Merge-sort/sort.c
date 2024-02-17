#include <stdio.h>
#include <limits.h>


void Merge(int A[], int b, int m, int e) {
	int n1 = m - b + 1;
	int n2 = e - m;
	int L[n1 + 1], R[n2 + 1];
	int i, j;
	for (i = 0; i < n1; i++) {
		L[i] = A[b + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = A[m + j + 1];
	}
	L[n1] = R[n2] = INT_MAX; 
	i = j = 0;
	for (int k = b; k <= e; k++) {
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void MergeSort(int A[], int b, int e) {
	if (b < e) {
		int m = (b + e) / 2;
		MergeSort(A, b, m);
		MergeSort(A, m + 1, e);
		Merge(A, b, m, e);
	}
}

int main(int argc, char const *argv[]) {
	
	printf("Input size of the array: ");
	int n;    scanf("%d", &n);   					// taking size of the array
	int arr[n];
	
	printf("Input your Array: ");					// taking array as Input
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\nYour array is : [ ");					// printing array before sorting
	for (int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	printf("]\n");

	MergeSort(arr, 0, n-1);		 					// parameters: array, starting index, ending index

	// Printing the array
	printf("Your sorted array is : [ ");			// printing array after sorting
	for (int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	printf("]\n");
	
	return 0;
}