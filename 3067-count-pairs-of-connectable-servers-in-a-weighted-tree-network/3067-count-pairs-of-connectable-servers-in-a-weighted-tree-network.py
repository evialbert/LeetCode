class Solution:
    def countPairsOfConnectableServers(self, edges, signalSpeed):
        graph, result, n = defaultdict(set), [], 0

        for i,j,k in edges:
            graph[i].add((j,k))
            graph[j].add((i,k))
            n = max(n,i,j)

        def dfs(node,parent,dist):
            count = int(dist%signalSpeed == 0)

            for neighbor,w in graph[node]:
                if neighbor != parent:
                    count += dfs(neighbor,node,dist+w)

            return count 

        for i in range(n+1):
            node_count, res = 0, 0 
            for neighbor,w in graph[i]:
                val = dfs(neighbor,i,w)
                res += node_count*val  
                node_count += val 
            result.append(res)

        return result 