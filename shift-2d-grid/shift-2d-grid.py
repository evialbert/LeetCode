class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        def applyShift(matrix):
            transpose = [list(x) for x in zip(*matrix)]
            transpose.insert(0, transpose.pop())
            transpose[0].insert(0, transpose[0].pop())
            transpose = [list(x) for x in zip(*transpose)]
            return transpose
        
        for trial in range(k):
            grid = applyShift(grid)
        return grid