class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        result = 0
        for i in range(0,len(s)):
            zero = 0
            ones = 0
            for j in range(i,len(s)):
                if s[j] == "0":
                    zero +=1
                else:
                    ones +=1
                if zero<= k or ones<=k:
                    result+=1
        return result