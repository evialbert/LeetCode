class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        s = sum(piles)
        c = 0
        for i in range(0,len(piles),2) :
            c += piles[i]
        c2 = 0
        for j in range(len(piles)-1,-1,-2) :
            c2 += piles[j]
        ans = max(c,c2)
        res = s - ans
        if res > ans :
            return False
        return True