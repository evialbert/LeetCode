class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True
        
        adjMap = self.buildAdjMap(edges)
        
        if source not in adjMap or destination not in adjMap:
            return False
        
        return self.BFS(n, source, destination, adjMap)
    
    def buildAdjMap(self, edges):
        adjMap = collections.defaultdict(list)
        for edge in edges:
            u, v = edge
            adjMap[u].append(v)
            adjMap[v].append(u)
        return adjMap
        
    def BFS(self, n, source, destination, adjMap):
        queue = collections.deque([source])
        visited = [0] * n
        visited[source] = 1
        while queue:
            vertex = queue.popleft()
            for neighbor in adjMap[vertex]:
                if neighbor == destination:
                    return True
                
                if visited[neighbor] == 0:
                    visited[neighbor] = 1
                    queue.append(neighbor)
                    
        return False