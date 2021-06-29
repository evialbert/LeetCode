class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
       int sum=0;
        int[] top = new int[grid[0].length];
        int[] left = new int[grid.length];
        for(int i=0;i<grid.length;i++)
        { int max=0;
            for(int j=0;j<grid[i].length;j++)
            {
               max= Math.max(max,grid[i][j]); 
            }
         left[i]=max;
        }
      int k=0;  
        while(k<grid[0].length)
        { int max=0;
        for(int i=0;i<grid.length;i++)
        {
           max= Math.max(max,grid[i][k]); 
        }
         top[k++]=max;
        }
        for(int i=0;i<top.length;i++)
        {
            for(int j=0;j<left.length;j++)
            {
                sum= sum+ Math.min(top[i],left[j])-grid[i][j];
            }
        }
        return sum;
    }
}