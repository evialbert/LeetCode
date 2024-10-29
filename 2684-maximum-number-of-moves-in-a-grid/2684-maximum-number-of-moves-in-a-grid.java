class Solution {
    int n,m;
    Integer[][] memo;
    public int maxMoves(int[][] grid) {
        int ans=0;
        n=grid.length;m=grid[0].length;
        memo=new Integer[n][m];
        for(int i=0;i<n;i++){
            ans=Math.max(ans,sol(grid,i,0));
        }
        return ans;
    }
    public int sol(int[][] grid,int r,int c){
        if(c==m-1) return 0;
        if(memo[r][c]!=null) return memo[r][c];
        int ans=0;
        if(grid[r][c]<grid[r][c+1]){
            ans=Math.max(ans,sol(grid,r,c+1)+1);
        }
        if(r>0 && grid[r][c]<grid[r-1][c+1]){
            ans=Math.max(ans,sol(grid,r-1,c+1)+1);
        }
        if(r<n-1 && grid[r][c]<grid[r+1][c+1]){
            ans=Math.max(ans,sol(grid,r+1,c+1)+1);
        }
        return memo[r][c]=ans;
    }
}