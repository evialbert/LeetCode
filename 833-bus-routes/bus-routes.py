class Solution:
    def numBusesToDestination(self, routes, source, target):
        n, graph = len(routes), defaultdict(list)

        for i in range(n):
            for j in routes[i]:
                graph[j].append(i)

        stack, visited = [(source,0)], set()

        while stack:
            node,count = stack.pop(0)

            if node == target:
                return count 

            for i in graph[node]:
                if i not in visited:
                    visited.add(i)
                    for j in routes[i]:
                        stack.append((j,count+1))

        return -1