class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        f, pq, mind = Counter(word), [], float('inf')
        for val in f.values(): heapq.heappush(pq, -val)
        while pq:
            t, d = -heapq.heappop(pq), 0
            for val in f.values():
                if val > t + k: d += val - (t + k)
                elif val < t: d += val
            if d < mind: mind = d
            if not mind: break
        return mind if mind != float('inf') else 0