class Solution:
    def numberOfEdgesAdded(self, n: int, edges: list[list[int]]) -> int:
        # parent[i] stores the root of node i
        parent = list(range(n))
        # dist[i] stores the parity of the path from node i to parent[i]
        dist = [0] * n
        
        def find(i):
            if parent[i] == i:
                return i, 0
            # Path compression while maintaining cumulative parity
            root, root_dist = find(parent[i])
            parent[i] = root
            dist[i] = (dist[i] + root_dist) % 2
            return parent[i], dist[i]

        def union(u, v, w):
            root_u, dist_u = find(u)
            root_v, dist_v = find(v)
            
            if root_u != root_v:
                # Connect the two components
                parent[root_u] = root_v
                # New dist[root_u] must satisfy: (dist_u + new_dist) % 2 == (w + dist_v) % 2
                dist[root_u] = (w + dist_u + dist_v) % 2
                return True
            else:
                # Cycle detected: check if existing path parity matches the new edge weight
                # Path parity between u and v is (dist_u + dist_v) % 2
                return (dist_u + dist_v) % 2 == w % 2

        count = 0
        for u, v, w in edges:
            if union(u, v, w):
                count += 1
                
        return count