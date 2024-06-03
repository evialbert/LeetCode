class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i = 0
        j = 0
        counter = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                j += 1
            i += 1

        if j < len(t):
            counter += len(t)-j
        return counter            