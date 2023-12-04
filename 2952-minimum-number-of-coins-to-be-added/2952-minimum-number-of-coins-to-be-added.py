class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        x, ans, i, n = 0, 0, 0, len(coins)
        while x < target:
            if i == n or coins[i] > x+1:
                # add the coin x+1
                ans += 1
                x += x + 1
            else:
                x += coins[i]
                i += 1
        return ans