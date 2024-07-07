class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = r = 0
        while numBottles:
            ans += numBottles
            numBottles, r = divmod(numBottles + r, numExchange)
        return ans 