class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        N = len(possible)
        pSum = [0]*(N+1)
        for i in range(1, N+1):
            if possible[i-1]==0:
                pSum[i] = pSum[i-1] - 1
            else:
                pSum[i] = pSum[i-1] + 1
        
        for i in range(1, N):
            d = pSum[i]
            b = pSum[-1] - pSum[i]
            if d > b: return i
        
        return -1