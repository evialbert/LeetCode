class Solution:
    def minSwaps(self, s: str) -> int:
        nest = 0
        for c in s:  nest = max(0, nest + 92 - ord(c))
        return (nest + 1) // 2