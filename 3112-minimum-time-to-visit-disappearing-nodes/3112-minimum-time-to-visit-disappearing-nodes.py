class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        # Get the adjcent graph base on the input, it is a undirected graph
        adj = defaultdict(list)
        for s, d, t in edges:
            adj[s].append([d, t])
            adj[d].append([s, t])
        
        # shortest records the shortest distance to each node, default is -1
        shortest = [-1] * n
        minHeap = [[0, 0]]
        while minHeap:
            # Get the lowest time from
            t1, n1 = heapq.heappop(minHeap)
            if shortest[n1] != -1: continue
            shortest[n1] = t1

            # check all the adjcent edge
            for n2, t2 in adj[n1]:
                # if n2 node disappear at this moment
                if disappear[n2] > t1 + t2:
                    heapq.heappush(minHeap, [t1 + t2, n2])

        return shortest

