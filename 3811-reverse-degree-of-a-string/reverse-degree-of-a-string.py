class Solution:
    def reverseDegree(self, s: str) -> int:
        d = {x: i+1 for i,x in enumerate("zyxwvutsrqponmlkjihgfedcba")}

        sum_ = 0
        for i in range(len(s)):
            sum_ += d[s[i]]*(i+1)

        return sum_
