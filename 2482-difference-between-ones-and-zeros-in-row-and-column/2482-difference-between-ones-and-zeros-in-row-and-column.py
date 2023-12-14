class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        l1=[]
        l2=[]
        for i in range(len(grid)):
            zero=0
            one=0
            for j in range(len(grid[i])):
                if(grid[i][j]==1):
                    one+=1
                else:
                    zero+=1
            l1.append([one,zero]) 

        for i in range(len(grid[0])):
            zero=0
            one=0
            for j in range(len(grid)):
                if(grid[j][i]==1):
                    one+=1
                else:
                    zero+=1
            l2.append([one,zero]) 
        # print(l1,l2)
        ans=grid.copy()
        # print(ans)
        for i in range(len(ans)):
            for j in range(len(ans[0])):
                ans[i][j] = l1[i][0]+l2[j][0]-l1[i][1]-l2[j][1]
        return ans
         