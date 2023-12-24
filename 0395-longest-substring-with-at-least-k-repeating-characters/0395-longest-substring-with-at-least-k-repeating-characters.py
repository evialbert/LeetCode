class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if not s:
            return 0

        if len(s) < k:
            return 0

        for i in set(s):
            if s.count(i)< k:
                return max([self.longestSubstring(substr, k) for substr in s.split(i)])

        
        return len(s)
