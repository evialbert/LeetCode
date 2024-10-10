class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for u,v in invocations:
            graph[u].append(v)

        def dfs(node,flag):
            visited.add(node)
            if flag:
                suspicious.add(node)
            for neighbor in graph[node]:
                if not flag and neighbor in suspicious:
                    return True  # we find a neighbor (normal node) that invokes suspicious group, return True
                if neighbor not in visited:
                    if dfs(neighbor,flag):
                        return True #early return True here if we find suspicious group cleared
                
        suspicious = set()
        visited = set()
        all_nodes = set([i for i in range(n)])
        dfs(k,True) # first get all suspicious nodes
        for node in range(n):
            if node not in suspicious and node not in visited:
                if dfs(node,False): # if true it means all groups are cleared, then we can just return all nodes
                    return list(all_nodes) 
        return list(visited-suspicious) 
            
        