class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)
        workers = sorted([(wage[i] / quality[i], quality[i]) for i in range(n)])
        
        min_cost = float('inf')
        quality_sum = 0
        heap = []
        
        for ratio, q in workers:
            quality_sum += q
            heapq.heappush(heap, -q)
            
            if len(heap) > k:
                quality_sum += heapq.heappop(heap)
            
            if len(heap) == k:
                min_cost = min(min_cost, ratio * quality_sum)
        
        return min_cost