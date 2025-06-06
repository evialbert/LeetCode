class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)
        res, stk = [], []

        min_suf = [''] * n
        min_suf[-1] = s[-1]
        for i in range(n - 2, -1, -1):
            min_suf[i] = min(s[i], min_suf[i + 1])

        for i in range(n):
            stk.append(s[i])
            while stk and (i == n - 1 or stk[-1] <= min_suf[i + 1]):
                res.append(stk.pop())

        return ''.join(res)