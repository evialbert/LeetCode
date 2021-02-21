class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        for row in grid:
            for elem in row:
                if elem < 0:
                    count += 1
        return count