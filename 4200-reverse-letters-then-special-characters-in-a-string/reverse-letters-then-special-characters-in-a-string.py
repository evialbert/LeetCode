class Solution:
    def reverseByType(self, s: str) -> str:
        l=[]
        c=[]
        for ch in s:
            if ch.islower():
                l.append(ch)
            else:
                c.append(ch)
        l.reverse()
        c.reverse()
        res=[]
        i=0
        r=0
        for ch in s:
            if ch.islower():
                res.append(l[i])
                i+=1
            else:
                res.append(c[r])
                r+=1
        return "".join(res)