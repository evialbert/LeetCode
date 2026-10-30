class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))

        best = [k + 1] * n  # best[x]: the shortest run x was settled with, k + 1 until then
        heap = [(0, 1, 0)]  # (distance, run, node): the walk ends with run nodes labeled labels[node]
        while heap:
            d, run, x = heappop(heap)
            if run >= best[x]:  # x was settled before, no farther away and with a run no longer
                continue
            if x == n - 1:
                return d
            best[x] = run
            for y, w in graph[x]:
                r = run + 1 if labels[y] == labels[x] else 1
                if r < best[y]:
                    heappush(heap, (d + w, r, y))
        return -1