class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        i = 0
        area = 0

        while i < len(heights):
            if stack == [] or heights[i] > heights[stack[len(stack) - 1]]:
                stack.append(i)
            else:
                cur = stack.pop()
                if stack == []:
                    width = i
                else:
                    width = i - stack[len(stack) - 1] - 1
                area = max(area, width * heights[cur])
                i -= 1
            i += 1

        while stack != []:
            cur = stack.pop()
            if stack == []:
                width = i
            else:
                width = len(heights) - stack[len(stack) - 1] - 1
            area = max(area, width * heights[cur])

        return area

    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if matrix == []:
            return 0
        a = [0 for i in range(len(matrix[0]))]
        maxArea = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == '1':
                    a[j] = a[j] + 1
                else:
                    a[j] = 0
            maxArea = max(maxArea, self.largestRectangleArea(a))
        return maxArea