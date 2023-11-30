class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        a = 0
        while n:
            a ^= n
            n >>= 1
        return a