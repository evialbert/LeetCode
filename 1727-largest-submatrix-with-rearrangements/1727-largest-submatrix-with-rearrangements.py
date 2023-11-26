class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        result=0
        max_ones=[0]*len(matrix[0])
        for row in matrix:
            for i, value in enumerate(row):
                max_ones[i]=0 if value==0 else max_ones[i]+1
            sorted_ones=sorted(max_ones)
            for i,h in enumerate(sorted_ones):
                result=max(result,h*(len(row)-i))
        return result