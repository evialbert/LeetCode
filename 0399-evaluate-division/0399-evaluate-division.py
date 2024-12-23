class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # directed graph as adjacency list 
        digraph = {} 
        for (u, v), w in zip(equations, values): 
            digraph.setdefault(u, []).append((v, w))
            digraph.setdefault(v, []).append((u, 1/w))
            
        # query 
        def dfs(u, v, w=1): 
            """Return division via dfs."""
            if u not in digraph: return -1 
            if u == v: return w
            seen.add(u)
            for uu, ww in digraph.get(u, []): 
                if uu not in seen and (ans := dfs(uu, v, w*ww)) != -1: return ans 
            return -1
        
        ans = []
        for u, v in queries: 
            seen = set()
            ans.append(dfs(u, v))
        return ans 