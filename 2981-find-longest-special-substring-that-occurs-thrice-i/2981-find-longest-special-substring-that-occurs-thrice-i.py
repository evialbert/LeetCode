class Solution:
    def maximumLength(self, s: str) -> int:
        from collections import Counter
        count = Counter(s)
        res =-1
        def check(s,tar):
            res = 0
            for i in range(len(s)):
                if i+len(tar)>len(s):
                    return res>=3
                if s[i:i+len(tar)]==tar:
                    res+=1
            return res>=3
        for i in count:
            if count[i]>=3:
                res=max(1,res)
                for j in range(count[i],1,-1):
                    if check(s,i*j):

                        res= max(res,j)

                        break

        return res