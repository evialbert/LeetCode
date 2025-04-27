class Solution:
    def baseUnitConversions(self, conversions: List[List[int]]) -> List[int]:
        ans = [1]*(len(conversions)+1)
        for start,end,cost in conversions:
            ans[end] =  (ans[start]*cost)%(10**9+7)

        return ans