class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        graph = {i:dict() for i in range(n)}
        for u,v,w in edges:
            graph[u][v] = w
            graph[v][u] = w
        
        neighbors = [0]*n
        
        for k in range(n):
            dist = [float('inf')]*n
            dist[k] = 0
            visited = [False]*n
            
            queue = [(0, k)]
            heapify(queue)
            
            count = -1

            while len(queue):
                minVal, minNode = heappop(queue)
                if minVal > distanceThreshold: break
                if visited[minNode]: continue
                visited[minNode] = True
                count += 1
                for node in graph[minNode]:
                    if not visited[node] and dist[minNode] + graph[minNode][node] < dist[node]:
                        dist[node] = dist[minNode] + graph[minNode][node]
                        heappush(queue, (dist[node], node))

            neighbors[k] = count
            
        curMin = neighbors[0]
        ans = 0
        for i in range(n):
            if neighbors[i] <= curMin:
                ans = i
                curMin = neighbors[i]

        return ans