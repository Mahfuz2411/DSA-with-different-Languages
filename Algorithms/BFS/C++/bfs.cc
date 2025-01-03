#include <bits/stdc++.h>
using namespace std;


// Define constants for the maximum number of vertices and a modulo value
const int N = 1e6+2, MOD = 1e9+2;

// unweighted graph
int n, m;
vector <int> g[N];

void graphInput() {
	// n vertex - m edges
	cout << "Enter the number of nodes & vertices(n m): \n";
	cin>>n>>m;

	// taking input
	cout << "Enter the edges (format: u v):\n";
	for(int i=0; i<m; i++) {
		int a, b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);  
	}
}

void bfs(int start) {
	vector <bool> v(n+1, 0);
	queue <int> q;
	q.push(start);
	// cout << "HEllo\n";

	while(q.size()) {
		int node = q.front();
		cout << node << ' ';
		v[node] = 1;
		q.pop();

		for(auto next: g[node]) {
			// cout << next << endl;
			if(v[next] == 0) q.push(next);
		}
	}
  
}

int main(int argc, char const *argv[]) {
	graphInput();
	int start;
	cout << "Start node?\n";
	cin >> start;
	bfs(start);
	cout << endl;
  	return 0;
}
