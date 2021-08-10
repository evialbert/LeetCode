class Solution {
    int [][]dp;
    public int minFallingPathSum(int[][] arr1) {
        int n=arr1.length;
        int res=Integer.MAX_VALUE;
        dp=new int[n+1][n+1];
        for(int []x1:dp)
        {
            Arrays.fill(x1,-1);
        }        
        for(int j=0;j<arr1[0].length;j++)
        {
            res=Math.min(res,solve(arr1,0,j));
        }
        
        return res;
    }
    
    public int solve(int [][]arr1,int row,int col)
    {
        if(row==arr1.length-1)
        {
            return arr1[row][col];
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int minPath=Integer.MAX_VALUE;
        int value=arr1[row][col];
        if(col-1>=0)
        {
            minPath=Math.min(minPath,value+solve(arr1,row+1,col-1));
        }
        if(col+1<arr1.length)
        {
            minPath=Math.min(minPath,value+solve(arr1,row+1,col+1)); 
        }
        minPath=Math.min(minPath,value+solve(arr1,row+1,col));
        dp[row][col]=minPath;
        return minPath;
    }    
}