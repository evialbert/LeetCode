class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        reverse_graph = defaultdict(list)
        for i in range(len(graph)):
            for edge in graph[i]:
                reverse_graph[edge].append(i)

        indegree = [0] * len(graph)
        for i in range(len(graph)):
            for node in reverse_graph[i]:
                indegree[node] += 1
        queue = deque([n for n in range(len(indegree)) if indegree[n] == 0])
        res = []
        while queue:
            node = queue.popleft()
            res.append(node)
            for edge in reverse_graph[node]:
                indegree[edge] -= 1
                if indegree[edge] == 0:
                    queue.append(edge)
        return sorted(res)

