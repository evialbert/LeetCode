class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        col=[]
        flag_for_col=True
        flag_for_row=True

        for r in range(len(grid)):
            for k in range(len(grid[0])-1):
                if (grid[r][k]==grid[r][k+1]):
                    flag_for_row=False


        for i in range(len(grid[0])):
            cols=[]
            for j in range(len(grid)):
                cols.append(grid[j][i])
            if len(set(cols))!=1:
                flag_for_col=False
            col.append(cols)
            
        if flag_for_row and flag_for_col:
            return (True)
        return (False)