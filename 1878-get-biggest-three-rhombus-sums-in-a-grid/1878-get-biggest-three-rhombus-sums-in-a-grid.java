class Solution {
    public int[] getBiggestThree(int[][] grid) {
        var res = new TreeMap<Integer,Integer>();
        int minLen = Math.min(grid.length, grid[0].length), sum;
        
        //iterate odd dimension square submatrices
        for(int size=1; size<= minLen; size+=2){
            //iterate all square submatrices of size "size"
            for(int i=size-1; i<grid.length; i++){
                for(int j=size-1; j<grid[0].length; j++){
                    sum = grid[i][j];
                    if(size > 1){
                        sum = sumBorder(grid, i, j, size);
                    }
                    if(res.containsKey(sum))
                        continue;//only distinct areas required
                    
                    res.put(sum,sum);
                    if(res.size() > 3)
                        res.pollFirstEntry();
                }
            }
        }
        int result[] = new int[res.size()],index = 0;
        while(!res.isEmpty())
            result[index++] = res.pollLastEntry().getKey();
        
        return result; 
    }
    private int sumBorder(int[][] grid,int x, int y, int size){
        
        int mid = size/2;
        //from bottom mid cell to left mid cell
        int i = x, j = y-mid, sum = 0;
        int count = 0;
        while(count++ < mid)
            sum += grid[--i][--j];
        
        //from left mid cell to top mid cell
        count = 0;
        while(count++ <mid)
            sum += grid[--i][++j];
        
        //from top mid cell to right mid cell
        count = 0;
        while(count++ <mid)
            sum += grid[++i][++j];
        
        //from right mid to bottom mid
        count = 0; 
        while(count++ < mid)
            sum += grid[++i][--j];
        
        return sum;
    }
}