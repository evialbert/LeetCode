class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int n=grid.length,m=grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(invalidgrid(grid,n,m,i,j))
                 return false;
            }
        }
        return true;
    }
    public boolean invalidgrid(int[][] grid,int n,int m,int i,int j){
        if(i<n-1 && grid[i][j]!=grid[i+1][j])
         return true;
         
        if(j<m-1 && grid[i][j]==grid[i][j+1])
         return true;
        
        return false;
    }
}