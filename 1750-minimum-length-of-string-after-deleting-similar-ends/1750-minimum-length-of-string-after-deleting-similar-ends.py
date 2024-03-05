class Solution:
    def minimumLength(self, s: str) -> int:
        f,r=0,len(s)-1
        while f<=r:
            if f==r and s[f]==s[r]:
                return 1
            if s[f]!=s[r]:
                return r-f+1
            e1,e2=f,r
            while e1<r and s[e1]==s[f]:
                e1+=1
            f=e1
            while e2>=0 and s[e2]==s[r]:
                e2-=1
            r=e2
        return 0