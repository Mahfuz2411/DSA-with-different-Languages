/*
This code is generated by chatgpt
according to my c++ code
*/

// Define constants for the maximum number of vertices
const N = 1e6 + 2;

// Unweighted graph
let n, m;
const g = Array.from({ length: N }, () => []);

// Function to input the graph (using constant values for this example)
function graphInput() {
  // n = number of nodes, m = number of edges
  n = 5;
  m = 4;

  // Example edges
  const edges = [
    [1, 2],
    [2, 3],
    [3, 4],
    [1, 5],
  ];

  console.log("Input edges:");
  for (let i = 0; i < m; i++) {
    const [a, b] = edges[i];
    g[a].push(b);
    g[b].push(a); // Since the graph is undirected
    console.log(`Edge ${i + 1}: ${a} <-> ${b}`);
  }
}

// BFS function
function bfs(start) {
  const visited = new Array(n + 1).fill(false);
  const queue = [];

  // Start BFS from the given node
  queue.push(start);
  visited[start] = true;

  console.log("BFS traversal:");
  while (queue.length > 0) {
    const node = queue.shift();
    console.log(node);

    for (const next of g[node]) {
      if (!visited[next]) {
        queue.push(next);
        visited[next] = true;
      }
    }
  }
}

// Main function
function main() {
  graphInput();
  const start = 1; // Example start node
  console.log(`Start node: ${start}`);
  bfs(start);
}

// Run the program
main();
