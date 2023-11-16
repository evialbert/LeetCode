class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        
        
        l=sorted([x for row in values for x in row])
        return sum(val*i for i,val in enumerate(l,1))
        