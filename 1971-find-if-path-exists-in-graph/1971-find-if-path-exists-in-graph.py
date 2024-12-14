class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        graph = {}
        for u, v in edges: 
            graph.setdefault(u, []).append(v)
            graph.setdefault(v, []).append(u)
        
        seen = {start}
        stack = [start]
        while stack: 
            n = stack.pop()
            if n == end: return True 
            for nn in graph.get(n, []): 
                if nn not in seen: 
                    seen.add(nn)
                    stack.append(nn)
        return False 