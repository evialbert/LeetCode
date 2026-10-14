class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""
        return '9' * (sum // 9) + str(sum % 9) * (sum % 9 > 0) + '0' * (num - (sum + 8) // 9)