class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        first, second = p.split('*')
        return first in s and second in s[s.index(first) + len(first):]