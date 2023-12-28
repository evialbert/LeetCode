class Solution:
    def getLengthOfOptimalCompression(self, s: str, y: int) -> int:
        n=len(s)
        d={}
        def find(x,y,p,c):
            if (x,y,p,c) in d:
                return d[(x,y,p,c)]
            if y<0:
                return float("inf")
            if x==n:
                return 0
            if s[x]==p:
                t=1 if c in [1,9,99] else 0
                r=t+find(x+1,y,p,c+1)
            else:
                r=min(find(x+1,y-1,p,c),1+find(x+1,y,s[x],1))
            d[(x,y,p,c)]=r
            return r
        return find(0,y,"",0)