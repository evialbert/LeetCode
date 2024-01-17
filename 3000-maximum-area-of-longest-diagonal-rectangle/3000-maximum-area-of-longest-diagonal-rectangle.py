class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int: 
        max_area, max_diag = 0, 0
        for a, b in dimensions:
            if (diag := a*a+b*b) > max_diag:
                max_diag = diag
                max_area = a*b
            elif diag == max_diag:
                max_area = max(a*b, max_area)
        return max_area