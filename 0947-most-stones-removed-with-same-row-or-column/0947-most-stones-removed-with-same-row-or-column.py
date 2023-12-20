class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        
        graph = collections.defaultdict(set)
        
        for r,c in stones:
            graph[f"r{r}"].add((r,c))
            graph[f"c{c}"].add((r,c))
        
        def dfs(r,c):
            for nr, nc in (graph[f"r{r}"] | graph[f"c{c}"]):
                if (nr, nc) not in seen:
                    seen.add((nr, nc))
                    dfs(nr, nc)
                    
        seen = set()
        islands = 0
        
        for r, c in stones:
            if (r,c) not in seen:
                seen.add((r,c))
                islands += 1
                dfs(r,c)
                
        return len(stones) - islands