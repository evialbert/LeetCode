class Solution:
    def maximumLength(self, s: str) -> int:
        i = 0
        d = {}
        max_len = -1
        while i<len(s):
            j = i+1
            while j<len(s) and s[j]==s[i]:
                j += 1
            temp = s[i:j]
            for k in range(min(len(temp),3)):
                d[temp[k:]] = d.get(temp[k:],0)+k+1
                if d[temp[k:]]>=3:
                    max_len = max(max_len, len(temp[k:]))
                    break
            i = j
        return max_len