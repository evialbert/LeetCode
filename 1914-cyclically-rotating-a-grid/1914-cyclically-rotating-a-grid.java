class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {
        
        int rowEnd = grid.length-1;
        int colEnd = grid[0].length-1;
        int rowStart= 0;
        int colStart =0;
       while(rowStart< rowEnd && colStart<colEnd){
        int mEnd = rowEnd;
        int nEnd = colEnd;
        int mStart= rowStart;
        int nStart =colStart;
           Queue<Integer> pq = new LinkedList<>();
           for(int j = nStart ; j<=nEnd; j++){
               pq.add(grid[mStart][j]);
           }
           mStart ++;
           for(int i=mStart; i<=mEnd; i++){
               pq.add(grid[i][nEnd]);
           }
           nEnd--;
           for(int j=nEnd; j>=nStart; j--){
               pq.add(grid[mEnd][j]);
           }
           mEnd--;
           for(int i=mEnd; i>=mStart; i--){
               pq.add(grid[i][nStart]);
           }
           nStart--;
          
           int mod=k;
           mod%=pq.size();
           while(mod>0){
               pq.add(pq.poll());
               mod--;
           }
        mEnd = rowEnd;
        nEnd = colEnd;
        mStart= rowStart;
        nStart =colStart;
          
           for(int j = nStart ; j<=nEnd; j++){
               grid[mStart][j] = pq.poll();
           }
           mStart ++;
           for(int i=mStart; i<=mEnd; i++){
               grid[i][nEnd]= pq.poll();
           }
           nEnd--;
           for(int j=nEnd; j>=nStart; j--){
               grid[mEnd][j]= pq.poll();
           }
           mEnd--;
           for(int i=mEnd; i>=mStart; i--){
               grid[i][nStart]= pq.poll();
           }
           nStart--;
           rowEnd--;
           colEnd--;
           rowStart++;
           colStart++;
           
       }
        return grid;
    }
}