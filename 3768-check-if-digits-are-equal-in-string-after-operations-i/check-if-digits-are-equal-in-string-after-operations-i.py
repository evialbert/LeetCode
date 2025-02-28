class Solution:
    def compute(self, s: str) -> str:
        res = ""
        for i in range(len(s) - 1):
            digit = (int(s[i]) + int(s[i+1])) % 10
            res += str(digit)
        return res
    def hasSameDigits(self, s: str) -> bool:
        res = s
        while len(res) > 2:
            res = self.compute(res)
        return res[0] == res[1]