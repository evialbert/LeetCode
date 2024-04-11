class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        queue = []
        neighbours = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    queue.append((i, j))
                else:
                    mat[i][j] = float('inf')

        idx = 0
        while idx < len(queue):
            row, col = queue[idx]
            idx += 1
            for i, j in neighbours:
                new_row, new_col = row + i, col + j
                if 0 <= new_row < rows and 0 <= new_col < cols and mat[new_row][new_col] > mat[row][col] + 1:
                    mat[new_row][new_col] = mat[row][col] + 1
                    queue.append((new_row, new_col))
        return mat