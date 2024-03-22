class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        rev = s[::-1]
        for i in range(1, len(s)):
            if s[i - 1] + s[i] in rev:
                return True
        return False