class Solution:
    def how_many(self, arr: list[int]) -> int:
        left: int = 0
        right: int = len(arr) - 1
        needed: int = 0
        while left < right:
            if arr[left] != arr[right]:
                needed += 1
            left += 1
            right -= 1
        return needed
    
    def minFlips(self, grid: List[List[int]]) -> int:
        needed_for_row: int = 0
        needed_for_col: int = 0
        for row in grid:
            needed_for_row += self.how_many(row)
        for col in range(len(grid[0])):
            cols: list[int] = [grid[row][col] for row in range(len(grid))]
            needed_for_col += self.how_many(cols)
        return min(needed_for_row, needed_for_col)