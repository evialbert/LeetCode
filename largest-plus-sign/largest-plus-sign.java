class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
      int grid[][][]=new int[N][N][4];
        for(int k=0;k<=3;k++){
            for(int a[] : mines)
                grid[a[0]][a[1]][k]=-1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                grid[i][j][0]=grid[i][j][0]==-1 ? 0 : j-1<0 ? 1 : grid[i][j-1][0]+1; 
               grid[i][j][1]=grid[i][j][1]==-1 ? 0 : i-1<0 ? 1 : 1+grid[i-1][j][1];  
            }
        }
          for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                grid[i][j][2]=grid[i][j][2]==-1 ? 0 : j+1>=N ? 1 : 1+grid[i][j+1][2]; 
               grid[i][j][3]=grid[i][j][3]==-1 ? 0 : i+1>=N ? 1 : 1+grid[i+1][j][3];  
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                ans=Math.max(ans,Math.min(grid[i][j][0],Math.min(grid[i][j][1],Math.min(grid[i][j][2],grid[i][j][3]))));
        }
        return ans;
    }
}