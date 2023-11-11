class Graph(object):
    def __init__(self, n, edges):
        self.n = n
        self.distance = [[float('inf')] * n for _ in range(n)]

        for i in range(n):
            self.distance[i][i] = 0

        for edge in edges:
            self.distance[edge[0]][edge[1]] = edge[2]

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    self.distance[i][j] = min(
                        self.distance[i][j],
                        self.distance[i][k] + self.distance[k][j]
                    )

    def addEdge(self, edge):
        if self.distance[edge[0]][edge[1]] <= edge[2]:
            return

        self.distance[edge[0]][edge[1]] = edge[2]

        for i in range(self.n):
            for j in range(self.n):
                self.distance[i][j] = min(
                    self.distance[i][j],
                    self.distance[i][edge[0]] + edge[2] + self.distance[edge[1]][j]
                )

    def shortestPath(self, node1, node2):
        if self.distance[node1][node2] == float('inf'):
            return -1
        return self.distance[node1][node2]
# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)