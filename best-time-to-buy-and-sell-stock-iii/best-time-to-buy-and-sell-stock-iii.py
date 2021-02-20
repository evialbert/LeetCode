class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        buyOne = 0x7ffffff
        SellOne = 0
        buyTwo = 0x7ffffff
        SellTwo = 0
        for p in prices:
            buyOne = min(buyOne, p)
            SellOne = max(SellOne, p - buyOne)
            buyTwo = min(buyTwo, p - SellOne)
            SellTwo = max(SellTwo, p - buyTwo)
        return SellTwo
