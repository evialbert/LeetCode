class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        import math
        numset = [i for i in range(1, n+1)]
        retnum = []
        k = k - 1
        while len(numset) > 1:
            n = n - 1
            index = k / math.factorial(n)
            retnum.append(str(numset[index]))
            k = k % math.factorial(n)
            numset.remove(numset[index])
        # The last number is added directly at the end
        retnum.append(str(numset[0]))
        return ''.join(retnum)