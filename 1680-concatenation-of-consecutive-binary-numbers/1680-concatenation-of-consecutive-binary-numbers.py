class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return int(''.join(bin(x)[2:] for x in range(1,n+1)),2)%(10**9+7)