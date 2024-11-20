class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        if k==0:return 0
        p,o,d,c,r,=len(s),0,{'a':0,'b':0,'c':0},3,0
        for e,v in enumerate(s):
            d[v]+=1
            if d[v]==k:
                c-=1
                if c:continue
                o=e+1
                break
        else: return -1
        for l in range(o-1,-1,-1):
            d[z:=s[l]]-=1
            while d[z]<k:d[s[r:=r-1]]+=1
            if l<=p-r:o=min(o,l-r)
        return o