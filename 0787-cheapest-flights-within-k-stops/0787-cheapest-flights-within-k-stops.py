class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        # src -> (dst, cost)
        graph = {}
        for edge in flights:
            graph[edge[0]] = graph.get(edge[0], [])
            graph[edge[0]].append((edge[1], edge[2]))

        # find cheapest flight between src and dst
        @cache
        def helper(src, dst, k):
            # print(src, dst, k)
            if k < 0:
                return math.inf

            ans = math.inf
            for neighbor in graph.get(src, []):
                # cheapest flight between neighbor and dst + cost of src and neighbor
                if neighbor[0] == dst:
                    ans = min(ans, neighbor[1])
                else:
                    ans = min(ans, helper(neighbor[0], dst, k - 1) + neighbor[1])

            return ans

        result = helper(src, dst, k)
        return -1 if result == math.inf else result