class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        y = str(x)
        t = [int(i) for i in y]
        add = sum(t)
        if x % add == 0: return add
        else: return -1