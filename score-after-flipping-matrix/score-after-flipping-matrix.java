class Solution {
    public int matrixScore(int[][] grid) {
        int col=grid[0].length,row=grid.length;
        // making all elements of first column 1
        for(int r=0;r<row;r++){
            if(grid[r][0]==1) continue;
            for(int i=0;i<col;i++){
                grid[r][i]^=1;//flip row bits
            }
           
        }
        //searching from 2nd column's each element and if no. of zeros are more than no of 1's then flip the colomn elements;
        for(int j=1;j<col;j++){
            int c0=0;
            for(int i=0;i<row;i++){
                if(grid[i][j]==0) c0++;
            }
            if(c0 >(row/2)){
                for(int i=0;i<row;i++){
                    grid[i][j]^=1;//flip row bits
                }
            }
        }
        return decimalArrRowSum(grid);
    }
    public int decimalArrRowSum(int[][] grid){
        int sum=0;
        for(int i=0;i<grid.length;i++){
            int rowSum=0;
            for(int j=0,pow=grid[i].length-1;j<grid[i].length;j++,pow--){
                rowSum+=grid[i][j] * (int)Math.pow(2,pow);
            }
            sum+=rowSum;
        }
        return sum;
    }
}