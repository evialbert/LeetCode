class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        MAX_INT = 2147483647
        sign = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else -1
        quotient = 0
        dividend = abs(dividend)
        divisor = abs(divisor)
        while dividend >= divisor:
            k = 0
            tmp = divisor
            while dividend >= tmp:
                dividend -= tmp
                quotient += 1 << k
                tmp <<= 1
                k += 1
        quotient  = sign * quotient
        if quotient > MAX_INT:
            quotient = MAX_INT
        return quotient
        