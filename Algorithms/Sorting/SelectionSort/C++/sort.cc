#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector <int> &v) {
  for(int i=0; i<v.size()-1; i++) {
    int minIdx = i;
    for(int j=i+1; j<v.size(); j++) {
      if(v[minIdx]>v[j])  minIdx = j;
    }
    swap(v[minIdx], v[i]);
  }
}

int main(int argc, char const *argv[]) {
  int n;   cin>>n;
  vector <int> v(n);
  for(auto &d : v) cin>>d;
  
  selectionSort(v);

  for(auto d: v) cout << d << ' ';
  cout << endl;
  return 0;
}