class Solution:
    def getSmallestString(self, s: str) -> str:
        def r(i, have_swapped):
            if i == len(s):
                return ""
            if i == len(s) - 1:
                return s[i]
            if (ord(s[i]) & 1) == (ord(s[i+1]) & 1) and s[i+1] < s[i] and not have_swapped:
                return s[i+1] + s[i] + r(i+2, True)
            else:
                return s[i] + r(i+1, have_swapped)
        return r(0, False)
        