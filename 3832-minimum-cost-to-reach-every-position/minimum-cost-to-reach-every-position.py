class Solution:
    def minCosts(self, cost: List[int]) -> List[int]:
        n = len(cost)
        minBefore = cost[:]
        min_val = cost[0]
        for i in range(1, n):
            minBefore[i] = min(minBefore[i], minBefore[i-1])
        
        return minBefore