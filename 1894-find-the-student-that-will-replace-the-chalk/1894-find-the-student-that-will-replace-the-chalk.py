class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        k %= sum(chalk)
        for i, num in enumerate(chalk):
            if k >= num: k -= num
            else: return i
        return -1