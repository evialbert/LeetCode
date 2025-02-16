class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        n = len(s)
        for l in range(n - k + 1):
            r = l
            while r < n - 1 and s[r + 1] == s[l] and r - l + 1 < k:
                r += 1
            if r - l + 1 == k:
                if (l > 0 and s[l - 1] == s[l]) or (r < n - 1 and s[r + 1] == s[l]):
                    continue
                return True
        return False
                