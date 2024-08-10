class Solution:
    def maxOperations(self, s: str) -> int:
        lis=[]
        n=len(s)
        ans=0
        las=-1
        ct=0
        for i in range(n):
            if s[i]=="1":
                if las+1<i :
                    ans+=ct
                las=i
                ct+=1
        if s[-1]!="1":
            ans+=ct        
        return ans            