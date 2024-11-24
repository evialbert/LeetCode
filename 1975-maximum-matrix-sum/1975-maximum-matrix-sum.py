class Solution:
    def maxMatrixSum(self, g: List[List[int]]) -> int:
        return sum(map(abs,chain(*g)))-(sum(v<0 for v in chain(*g))%2 and min(map(abs,chain(*g)))*2)