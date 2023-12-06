class Solution:
    def totalMoney(self, n: int) -> int:
        return sum((7 if not x%7 else x%7)+(x-1)//7 for x in range(1,n+1))