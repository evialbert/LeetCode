class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        n=len(horizontalCut)
        m=len(verticalCut)
        i=0
        j=0
        h=1
        v=1
        cost=0
        while(i<n and j<m):
            if(horizontalCut[i]>verticalCut[j]):
                cost+=horizontalCut[i]*v
                h+=1
                i+=1
            else:
                cost+=verticalCut[j]*h
                v+=1
                j+=1
        while(i<n):
            cost+=horizontalCut[i]*v
            h+=1
            i+=1
        while(j<m):
            cost+=verticalCut[j]*h
            v+=1
            j+=1
        return cost