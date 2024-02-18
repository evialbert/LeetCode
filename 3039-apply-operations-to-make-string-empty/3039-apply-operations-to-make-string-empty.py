class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        d=collections.Counter(s)
        m=max(d.values())
        k={}
        for i in d:
            if d[i]==m:
                k[i]=s.rindex(i)
        z=sorted(k.items(), key=lambda item: item[1]) 
        res=""
        for i in z:
            res+=i[0]
        return res