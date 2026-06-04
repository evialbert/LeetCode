class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        s, x = str(n), str(x)
        return x!=s[0] and x in s