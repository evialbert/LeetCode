class Solution:
    def minimumCost(self,x:int,y:int,k:int,i:int,j:int)->int:
        return(i*x)+(j*y)if(i*x)+(j*y)<min(k*max(i,j),k*min(i,j)+(i-min(i,j))*x+(j-min(i,j))*y)else min(k*max(i,j),k*min(i,j)+(i-min(i,j))*x+(j-min(i,j))*y)