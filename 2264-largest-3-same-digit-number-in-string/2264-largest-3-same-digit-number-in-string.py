class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res = -1
        for i in range(len(num)-2):
            if num[i] == num[i+1] == num[i+2]:
                res = max(res, int(num[i:i+3]))
        if res == 0:
            return '000'
        if res == -1:
            return ""
        return str(res)
    