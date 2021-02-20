class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """ 
        d=2**31-1
        while (m&d) != (n&d):
            d<<=1 
        return (m&d)
        