class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        laddersUsed = []

        for i in range(len(heights) - 1):
            diff = heights[i + 1] - heights[i]
            if diff <= 0:
                continue
            
            heapq.heappush(laddersUsed, diff)
            if ladders:
                ladders -= 1
                continue
            
            bricks -= heapq.heappop(laddersUsed)
            if bricks < 0:
                return i
        
        return len(heights) - 1