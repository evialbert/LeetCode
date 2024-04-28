class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = defaultdict(set)
        for u, v in edges: graph[u].add(v), graph[v].add(u)

        def dfs1(u, l):
            if u in seen: return
            seen.add(u)
            total[0] += l
            for v in graph[u]: dfs1(v, l + 1) 

        def dfs2(u):
            if u in seen: return 0
            seen.add(u)
            ans = 1 + sum(dfs2(v) for v in graph[u])
            counts[u] = ans
            return ans

        def dp(u, parent):
            if u in seen: return
            seen.add(u)
            if u != 0: ans[u] = ans[parent] + n - 2 * counts[u] 
            for v in graph[u]: dp(v, u)

        total, seen = [0], set()
        dfs1(0, 0)
        counts, seen = [0] * n, set()
        dfs2(0)
        ans, seen = [total[0]] * n, set()
        dp(0, 0)
        return ans