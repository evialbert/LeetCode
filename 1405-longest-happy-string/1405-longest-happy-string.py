class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap = [(-a, 'a'), (-b, 'b'), (-c, 'c')]
        heapq.heapify(heap)
        res = ''
        prev = None
        while len(heap) > 0:
            count, char = heapq.heappop(heap)
            count = -count
            req_chars = min(2, count)
            if prev and -prev[0] > count:
                req_chars = min(1, count)
            if prev and count > 0:
                heapq.heappush(heap, prev)
                prev = None
            res += char * req_chars
            count -= req_chars
            prev = (-count, char)
        
        return res