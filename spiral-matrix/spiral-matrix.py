class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = []
        while matrix:
            # add the first row
            res += matrix.pop(0)
            
            # add the right-most col
            if matrix and matrix[0]:
                for row in matrix:
                    res.append(row.pop())
            # add the bottom row from right to left            
            if matrix:
                res += matrix.pop()[::-1]
                
            # add the left-most col from bottom to up
            if matrix and matrix[0]:
                res += [row.pop(0) for row in matrix][::-1]
                
        return res
