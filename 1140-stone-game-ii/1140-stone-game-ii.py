class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        @cache
        def calc(i, m, turn):
            if i >= len(piles):
                return 0
            ans = 0 if turn else float('inf')
            curr = 0
            for j in range(i, min(i+2*m, len(piles))):
                if turn:
                    curr += piles[j]
                    ans = max(ans, calc(j+1, max(m, j-i+1), not turn)+curr)
                else:
                    ans = min(ans, calc(j+1, max(m, j-i+1), not turn))
            
            return ans

        return calc(0, 1, True)
