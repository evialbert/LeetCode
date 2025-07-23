class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x < y:
            s = s[::-1]
            x, y = y, x

        a = b = 0
        res = 0

        for ch in s:
            if ch == 'a':
                a += 1
            elif ch == 'b':
                if a > 0:
                    a -= 1
                    res += x
                else:
                    b += 1
            else:
                res += min(a, b) * y
                a = b = 0

        return res + min(a, b) * y