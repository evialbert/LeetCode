class Solution:
    def maximizeSumOfWeights(self, edges: List[List[int]], k: int) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))

        @cache
        def dfs(u, p, fd):
            l = []
            for v, w in g[u]:
                if v == p:
                    continue
                l.append((dfs(v, u, 0) + w, dfs(v, u, 1)))
            
            l.sort(key=lambda c: c[0] - c[1], reverse=True)
            d = k - (1 - fd)
            ans = 0
            for i in range(len(l)):
                ans += max(l[i][0], l[i][1]) if i < d else l[i][1]
            return ans
        
        return dfs(0, -1, 1)