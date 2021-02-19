class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        copy_matrix = copy.deepcopy(matrix)
        for i in range(len(copy_matrix)):
            for j in range(len(copy_matrix)):
                matrix[j][len(copy_matrix)-1-i] = copy_matrix[i][j]