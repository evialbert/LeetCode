class Solution:
    def countKeyChanges(self, s: str) -> int:
        res = 0
        prev = s[0]
        for c in s:
            if c.lower() != prev.lower():
                res += 1
                prev = c
        
        return res