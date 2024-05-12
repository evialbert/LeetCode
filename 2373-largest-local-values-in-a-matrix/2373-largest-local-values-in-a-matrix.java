class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n=grid.length;
        int[][] maxLocal=new int[n-2][n-2];
        
        
        for(int i=0;i<=grid.length-3;i++){
            
            for(int j=0;j<=grid.length-3;j++){
                maxLocal[i][j]=max(grid,i,j);
            }
            
        }
    
    return maxLocal;
    }
        
        public int max(int[][] grid,int i,int j){
            
            int mx=Integer.MIN_VALUE;
            
            for(int row=i;row<i+3;row++){
                for(int col=j;col<j+3;col++){
                    if(grid[row][col]>mx){
                        mx=grid[row][col];
                    }
                }
            }
            
            return mx;
        }
        
        
    }