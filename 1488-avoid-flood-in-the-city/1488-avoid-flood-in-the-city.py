class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        pq = []
        fill = set()
        d = collections.defaultdict(list)
        ans = []
        
        for i, rain in enumerate(rains):
            d[rain].append(i)
        
        for rain in rains:
            if rain > 0:
                if rain in fill:
                    return []
                fill.add(rain)
                d[rain].pop(0)
                if d[rain]:
                    heapq.heappush(pq, d[rain][0])
                ans.append(-1)
            else:
                if pq:
                    ind = heapq.heappop(pq)
                    ans.append(rains[ind])
                    fill.remove(rains[ind])
                else:
                    ans.append(1)
        
        return ans