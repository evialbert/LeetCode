class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        MOD = 10**9+7
        for i in reversed(range(n)):
            mask = 1 << i
            if (a & mask) and (b & mask):
                continue
            elif (a & mask):
                if a > b:
                    a ^= mask
                    b |= mask
            elif (b & mask):
                if a < b:
                    a |= mask
                    b ^= mask
            else:
                a |= mask
                b |= mask
        a %= MOD
        b %= MOD
        return (a * b) % MOD