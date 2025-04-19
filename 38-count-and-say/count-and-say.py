class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        return self.converter(self.countAndSay(n - 1))

    def converter(self, num: str) -> str:
        i = 0
        res = ""
        while i < len(num):
            cnt = 1
            while i + 1 < len(num) and num[i] == num[i + 1]:
                cnt += 1
                i += 1
            res += str(cnt) + num[i]
            i += 1
        return res