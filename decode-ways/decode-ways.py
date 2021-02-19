class Solution:
    def numDecodings(self, s: str) -> int:
        if s == '0' or len(s) == 0 :
            return 0
        if len(s) == 1:
            return 1
        res = [0] * (len(s) + 1)
        res[0] = 1
        for i in range(1, len(res)):
            if s[i-1] != '0':
                res[i] = res[i-1]
            if i != 1 and '10' <= s[i-2:i] <= '26':
                res[i] += res[i-2]
        return res[-1]