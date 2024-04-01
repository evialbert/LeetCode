class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        n = len(s)
        count = 0
        for i in range(n-1,-1,-1):
            if s[i] == " ":
                return count
            else:
                count+=1
        return count