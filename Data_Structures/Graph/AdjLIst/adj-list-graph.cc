// You can't do anything until you try

// Include necessary C++ standard library headers
#include<bits/stdc++.h>
using namespace std;

// Define constants for the maximum number of vertices and a modulo value
const int N = 1e6+2, MOD = 1e9+2;

// unweighted graph
int n, m;
vector <int> g[N];

void graphInput() {
    // n vertex - m edges
    cin>>n>>m;

    // taking input
    cout << "Enter the edges (format: u v):\n";
    for(int i=0; i<m; i++) {
        int a, b;
        g[a].push_back(b);

        /*
        you need to use also 
        g[b].push_back(a);
        for undirected graph
        */
    }
}

void printGraph() {
    for(int i=0; i<n; i++) {
        cout << i << " -> ";
        for(auto d: g[i]) {
            cout << d << ' ' ;
        }
        cout << endl;
    }
}

// Main function
int main(int argc, char const *argv[]){
    graphInput();  // Call the function to input the graph
    printGraph();
    return 0;
}
