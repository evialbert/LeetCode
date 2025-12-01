class Solution:
    def longestBalanced(self, s: str) -> int:
        n,ans=len(s),0
        i=0
        while i<n:
            j=i
            while j<n and s[j]==s[i]:
                j+=1
            ans=max(ans,j-i)
            i=j

        def best_2(x,y,third):
            best,i=0,0
            while i<n:
                if s[i]==third:
                    i+=1
                    continue
                st,bal=i,0
                fst={0:st}
                j=st
                while j<n and s[j]!=third:
                    bal+=1 if s[j]==x else -1
                    if bal not in fst:
                        fst[bal]=j+1
                    else:
                        best=max(best,j+1-fst[bal])
                    j+=1
                i=j
            return best

        ans=max(ans,best_2('a','b','c'))
        ans=max(ans,best_2('a','c','b'))
        ans=max(ans,best_2('b','c','a'))

        ca,cb,cc=0,0,0
        mp={(0,0):-1}
        for i,ch in enumerate(s):
            if ch=='a':
                ca+=1
            elif ch=='b':
                cb+=1
            else:
                cc+=1
            k=(ca-cb,ca-cc)
            if k in mp:
                ans=max(ans,i-mp[k])
            else:
                mp[k]=i
        return ans
                