n = int(input("Enter the number of nodes: "))
m = int(input("Enter the number of vertices: "))

g = {}

print("Enter the edges (format: u v):")
for _ in range(m):
    u, v = list(map(int, input().split()))[:2]
    if u not in g: g[u] = []
    if v not in g: g[v] = []
    
    g[u].append(v)
    g[v].append(u)  # for undirected graphs


# codes of dfs start from here
vis = [0]*(n+1)
que = []


que.append(int(input("Enter start node: ")))

while len(que) > 0:
    node = que[-1]
    que.pop()
    vis[node] = 1
    
    print(node, end=" ")
    
    for next in g[node]:
        if vis[next] == 0:
             que.append(next)

print()