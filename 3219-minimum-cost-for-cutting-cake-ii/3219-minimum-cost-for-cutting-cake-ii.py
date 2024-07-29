class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        h=horizontalCut
        v=verticalCut
        h.sort(reverse=1)
        v.sort(reverse=1)
        i=0
        j=0
        ans=0
        h1=1
        v1=1
        while i<len(h) or j<len(v):
            if (j==len(v)) or (i<len(h) and (h[i]>=v[j])):
                ans+=h[i]*v1
                h1+=1
                i+=1
            else:
                ans+=v[j]*h1
                v1+=1
                j+=1
            #print(ans)
        #print(v1,h1)
        return ans