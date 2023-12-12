class Solution:
    def numberOfSets(self, n: int, max_distance: int, roads: List[List[int]]) -> int:
        total_sets = 0

        for i in range(1 << n):
            graph = [[float('inf')] * n for _ in range(n)]

            for x, y, w in roads:
                if ((i >> x) & 1) and ((i >> y) & 1):
                    graph[x][y] = min(graph[x][y], w)
                    graph[y][x] = min(graph[y][x], w)

            for j in range(n):
                graph[j][j] = 0

            for p in range(n):
                for q in range(n):
                    for k in range(n):
                        graph[q][k] = min(graph[q][k], graph[q][p] + graph[p][k])

            is_valid_set = 1
            for j in range(n):
                for k in range(n):
                    if ((i >> j) & 1) and ((i >> k) & 1):
                        is_valid_set &= 1 if graph[j][k] <= max_distance else 0

            total_sets += is_valid_set

        return total_sets
