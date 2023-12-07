class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        pos=-prices[0]
        profit=0
        for i in range(1,len(prices)):
            pos=max(pos,profit-prices[i])
            profit=max(profit,pos+prices[i]-fee)
        return profit