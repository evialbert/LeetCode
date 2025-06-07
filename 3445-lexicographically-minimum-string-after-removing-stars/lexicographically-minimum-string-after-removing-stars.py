class Solution:
    def clearStars(self, s: str) -> str:
        n = len(s)
        result = [''] * n
        heap = []
        
        for idx, char in enumerate(s):
            if char == '*':
                heapq.heappop(heap)
            else:
                heapq.heappush(heap, (char, -idx))
                
        while heap:
            char, idx = heapq.heappop(heap)
            result[-idx] = char
            
        return ''.join(result)        