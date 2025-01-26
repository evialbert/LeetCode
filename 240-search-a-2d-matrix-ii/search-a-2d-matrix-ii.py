class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        i, j = 0, n-1
        while i < m and 0 <= j: 
            if matrix[i][j] < target: i += 1
            elif matrix[i][j] == target: return True 
            else: j -= 1
        return False 