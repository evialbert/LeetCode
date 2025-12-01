class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort()
        k = len(batteries) - n
        x = sum(batteries[:k])
        batteries = batteries[k:]
        for i in range(1, n):
            y = (batteries[i] - batteries[i - 1]) * i
            if y <= x:
                x -= y
            else:
                return batteries[i - 1] + x // i
        return batteries[-1] + x // n