class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        all_row, all_col = len(grid), len(grid[0])

        result = 0
        one, one_plus_or_minus_region = 0, 0
        for row in range(ceil(all_row / 2)):
            for col in range(ceil(all_col / 2)):
                a, b, c, d = grid[row][col], grid[all_row - row - 1][col], grid[all_row - row - 1][all_col - 1 - col], grid[row][all_col - 1 - col]

                if all_row - 1 - row != row and all_col - 1 - col != col:
                    s = a + b + c + d
                    result += min(4 - s, s - 0)
                elif all_row - 1 - row == row and all_col - 1 - col == col:
                    one += a  # max = 1
                elif all_row - 1 - row == row and all_col - 1 - col != col:
                    one += (a + c) # max = 2
                    if a + c == 1:
                        one_plus_or_minus_region += 1
                else:
                    one += (a + b) # max = 2
                    if a + b == 1:
                        one_plus_or_minus_region += 1

        result += one_plus_or_minus_region

        min_t_add = 4
        for t in range(one - one_plus_or_minus_region, one + one_plus_or_minus_region + 1, 2):
            min_t_add = min(min_t_add, t % 4)
        result += min_t_add

        return result