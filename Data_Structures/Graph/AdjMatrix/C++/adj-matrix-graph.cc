#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  
    cout << "Enter the number nodes: ";
    cin >> n;

    int graph[n][n];

    for(int i=0; i<n; i++) {
        int j;
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for(int i=0; i<m; i++) {
        int a, b; 

        cin>> a>> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    
    for(int i=0; i<n; i++) {
        int j;
        for(j=0; j<n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}