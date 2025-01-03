from collections import deque, defaultdict

class Graph:
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adj_list = defaultdict(list)

    def add_edge(self, u, v):
        """Adds an edge between nodes u and v (undirected graph)."""
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def bfs(self, start_node):
        """Performs BFS traversal from the start_node and prints the order of traversal."""
        visited = [False] * (self.num_nodes + 1)
        queue = deque([start_node])
        visited[start_node] = True

        while queue:
            node = queue.popleft()
            print(node, end=" ")
            visited[node] = True
            
            for neighbor in self.adj_list[node]:
                if not visited[neighbor]:
                    queue.append(neighbor)

# Input and usage
def main():
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))

    graph = Graph(n)

    print("Enter the edges (format: u v):")
    for _ in range(m):
        u, v = map(int, input().split())
        graph.add_edge(u, v)

    start_node = int(input("Enter start node: "))
    print("BFS Traversal:")
    graph.bfs(start_node)

if __name__ == "__main__":
    main()
