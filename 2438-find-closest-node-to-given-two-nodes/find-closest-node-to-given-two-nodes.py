class Solution:
    def closestMeetingNode(self, edges: list[int], node1: int, node2: int) -> int:
        n = len(edges)
        
        def build_dist(start: int) -> list[int]:
            dist = [float('inf')] * n
            cur, d = start, 0
            while cur != -1 and dist[cur] == float('inf'):
                dist[cur] = d
                d += 1
                cur = edges[cur]
            return dist
        
        dist1 = build_dist(node1)
        dist2 = build_dist(node2)
        
        answer, best = -1, float('inf')
        for i in range(n):
            d = max(dist1[i], dist2[i])
            if d < best:
                best, answer = d, i
        
        return answer