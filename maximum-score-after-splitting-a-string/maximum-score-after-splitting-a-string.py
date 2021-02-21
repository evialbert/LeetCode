class Solution:
    def maxScore(self, s: str) -> int:
        if "0" not in s or "1" not in s:
            return len(s)-1
        else:
            count=[]
            for i in range(1,len(s)):
                sl=s[:i]
                sr=s[i:]
                count.append(sl.count("0")+sr.count("1"))
            return max(count)