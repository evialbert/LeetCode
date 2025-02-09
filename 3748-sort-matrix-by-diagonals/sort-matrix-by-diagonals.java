class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int[][] res = new int[m][n];
        int r=0;
        int c=m;
        while(r<n && c>=0){
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            for(int i=r,j=0;i<n&&j<c;i++,j++){
                pq.add(grid[i][j]);
            }
            for(int i=r,j=0;i<n&&j<c;i++,j++){
                res[i][j]=pq.poll();
            }
            c--;
            r++;
        }
        r=n-1;
        c=1;
        while(r<n && c<m){
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for(int i=0,j=c;i<r&&j<m;i++,j++){
                pq.add(grid[i][j]);
            }
            for(int i=0,j=c;i<r&&j<m;i++,j++){
                res[i][j]=pq.poll();
            }
            c++;
            r--;
        }
        return res;
    }
}