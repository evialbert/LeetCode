class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return False if n <= 0 else n & (n - 1) == 0