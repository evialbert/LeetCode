class Solution(object):
    def getGoodIndices(self, variables, target):
        """
        :type variables: List[List[int]]
        :type target: int
        :rtype: List[int]
        """
        c = []
        for i in range(len(variables)):
            if (((variables[i][0] ** variables[i][1]) % 10) ** variables[i][2]) % variables[i][3] == target:
                c.append(i)
        return c
                