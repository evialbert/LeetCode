
class Solution:
    def minMergeCost(self, lists: List[List[int]]) -> int:
        n = len(lists)
        full_mask = (1 << n) - 1
        
        length = [0] * (1 << n)
        med = [0] * (1 << n)
        
        for mask in range(1, 1 << n):
            elements = []
            for i in range(n):
                if mask & (1 << i):
                    elements.extend(lists[i])
            elements.sort()
            length[mask] = len(elements)
            med[mask] = elements[(len(elements) - 1) // 2]
        
        dp = [0] * (1 << n)
        
        for mask in range(1, 1 << n):
            if mask & (mask - 1) == 0:
                dp[mask] = 0
                continue
            
            best = float('inf')
            
            submask = (mask - 1) & mask
            while submask > 0:
                other = mask ^ submask
                if submask < other:
                    cost = dp[submask] + dp[other] + length[submask] + length[other] + abs(med[submask] - med[other])
                    best = min(best, cost)
                submask = (submask - 1) & mask
            
            dp[mask] = best
        
        return dp[full_mask]