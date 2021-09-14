class Solution {
    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        dfs(grid,row,col,color,grid[row][col],new boolean[grid.length][grid[0].length]);
        return grid;
    }
    public void dfs(int[][] grid,int row,int col,int color,int pcolor,boolean[][] visited){
        visited[row][col]=true;
        int count=0;
        if(row-1>=0){
            if(visited[row-1][col]==true){
                count++;
            }else if(grid[row-1][col]==pcolor){
                count++;
                dfs(grid,row-1,col,color,pcolor,visited);
            }
        }
        if(col-1>=0){
           if(visited[row][col-1]==true){
                count++;
            }else if(grid[row][col-1]==pcolor){
                count++;
                dfs(grid,row,col-1,color,pcolor,visited);
            } 
        }
        if(col+1<grid[0].length){
           if(visited[row][col+1]==true){
                count++;
            }else if(grid[row][col+1]==pcolor){
                count++;
                dfs(grid,row,col+1,color,pcolor,visited);
            } 
        }
        if(row+1<grid.length){
           if(visited[row+1][col]==true){
                count++;
            }else if(grid[row+1][col]==pcolor){
                count++;
                dfs(grid,row+1,col,color,pcolor,visited);
            } 
        }
        if(count!=4){
            grid[row][col]=color;
        }
    }
}