class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        
        ans = [0,0]
        n = len(grid)
        for row in range(len(grid)):
            for col in range(len(grid)):
                val = abs(grid[row][col])
                valRow = (val -1)//n
                valCol = (val -1) % n

                if grid[valRow][valCol] < 0:
                    ans[0] = val
                else:
                    grid[valRow][valCol] *= -1
                
        for row in range(len(grid)):
            for col in range(len(grid)):
                if grid[row][col] > 0:
                    ans[1] = row*n + col + 1
        return ans