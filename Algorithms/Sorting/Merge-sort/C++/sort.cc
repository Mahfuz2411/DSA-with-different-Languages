#include <bits/stdc++.h>
using namespace std;

class Msort {
    void Merge(vector<int> &A, int b, int m, int e);
    public:
    void MergeSort(vector<int> &A, int b, int e);
    void printVector(vector<int> &A);
};

void Msort::Merge(vector<int> &A, int b, int m, int e) {
    int n1 = m - b + 1;
    int n2 = e - m;
    vector<int> L(n1 + 1), R(n2 + 1);
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

void Msort::MergeSort(vector<int>& A, int b, int e) {
    if(b<e){
        int m = (b+e)/2;
        MergeSort(A, b, m);
        MergeSort(A, m+1, e);
        Merge(A, b, m, e);
    }
}

void Msort::printVector(vector<int> &A) {
    cout << "[ ";
    for (auto d : A) {
        cout << d << ' ';
    }
    cout << ']' << endl;
}

int main(int argc, char const *argv[]) {

    cout << "Input size of the array: ";
    int n;   cin>>n;                        //taking size of the array
    vector <int> arr(n); 

    cout << "Input the array: ";
    for(auto &d: arr) cin>>d;               //array input

    Msort msort;                            // Object creation
    
    cout << endl << "Your Array is: ";
    msort.printVector(arr);                 // Printing array before sorting
    msort.MergeSort(arr, 0, arr.size()-1);  // parameters: array, starting index, ending index
    cout << "Your Sorted Array is: ";
    msort.printVector(arr);                 // Printing array after sorting
    return 0;
}