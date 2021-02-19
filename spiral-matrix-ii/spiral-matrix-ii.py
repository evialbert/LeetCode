class Solution:

    def generateMatrix(self, n):

        """

        :type n: int

        :rtype: List[List[int]]

        """



        # approach: put in number by order: right, down, left and up



        result = [[0] * n for i in range(n)]

        x = y = 0

        left = top = 0

        right = bottom = n - 1

        current = 1



        while current <= n * n:

            # go right

            for i in range(left, right + 1):

                result[top][i] = current

                current += 1

            top += 1



            # go down

            for i in range(top, bottom + 1):

                result[i][right] = current

                current += 1

            right -= 1



            # go left

            for i in range(right, left - 1, -1):

                result[bottom][i] = current

                current += 1

            bottom -= 1



            # go top

            for i in range(bottom, top - 1, -1):

                result[i][left] = current

                current += 1

            left += 1



        return result