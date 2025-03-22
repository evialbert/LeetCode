class Solution:
    def dfs(self, start: int, adj_list: list[list[int]], components: list[int], component: int) -> int:
        components[start] = component
        edges: int = 1
        q: list[int] = [start]
        while q:
            vertex: int = q.pop()
            for neighbor in adj_list[vertex]:
                if components[neighbor] == -1:
                    edges += 1
                    components[neighbor] = component
                    q.append(neighbor)
        return edges

    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_list: list[list[int]] = [[] for _ in range(n)]
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        components: list[int] = [-1] * n
        components_edges: list[int] = []
        component: int = 0
        for vertex in range(n):
            if components[vertex] == -1:
                amount_edges: int = self.dfs(vertex, adj_list, components, component)
                component += 1
                components_edges.append(amount_edges)
        complete_components: int = component
        for vertex in range(n):
            if components_edges[components[vertex]] != len(adj_list[vertex]) + 1:
                if components_edges[components[vertex]] != -1:
                    complete_components -= 1
                    components_edges[components[vertex]] = -1
        return complete_components