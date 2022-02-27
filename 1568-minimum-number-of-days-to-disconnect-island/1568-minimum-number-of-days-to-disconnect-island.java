class Solution {
    public int minDays(int[][] grid) {
        int n = grid.length ;
        int m = grid[0].length ;
        if(numIslands(grid) != 1){
          return 0;
        }
        for(int i = 0; i < n;i++ ){
          for(int j = 0 ; j < m ; j++){
              if(grid[i][j] == 1){
                 grid[i][j] = 0;
                
                 if(numIslands(grid) != 1){
                   return 1;
                 }
                 
                 grid[i][j] = 1;
              }
          }
        }
      return 2;
    }
  public int numIslands(int[][] grid) {
        int count = 0;
        boolean visited[][] = new boolean[grid.length][grid[0].length];
        
        for(int i = 0;i < grid.length;i++){
            for(int j = 0;j < grid[0].length;j++){
                if(grid[i][j] != 0 && visited[i][j] == false){
                   
                    count++;
                    countIslands(grid,i,j,visited);
                }
            }
        }
        return count;
    }
  private void countIslands(int grid[][],int i,int j,boolean visited[][]){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0 || visited[i][j] == true){
        return;    
        } 
         visited[i][j] = true;
         countIslands(grid,i - 1,j,visited);
         countIslands(grid,i + 1,j,visited);
         countIslands(grid,i,j - 1,visited);
         countIslands(grid,i,j + 1,visited);
        
        
    }
}