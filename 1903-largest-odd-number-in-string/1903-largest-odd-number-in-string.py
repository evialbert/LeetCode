class Solution:
    def largestOddNumber(self, num: str) -> str:
        return num[:max(num.rfind(d) for d in '13579')+1]