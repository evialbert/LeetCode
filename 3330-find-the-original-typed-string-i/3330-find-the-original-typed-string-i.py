class Solution:
    def possibleStringCount(self, word: str) -> int:
        return sum(a == b for a, b in pairwise(word)) + 1