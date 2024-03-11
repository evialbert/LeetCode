class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] freqsY = new int[3];
        int[] freqsNonY = new int[3];
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i >= n/2 && j == n/2){
                    freqsY[grid[i][j]]++;
                }
                else if(j < n/2 && i == j){
                    freqsY[grid[i][j]]++;
                }
                else if(j > n/2 && i + j == n-1){
                    freqsY[grid[i][j]]++;
                }
                else{
                    freqsNonY[grid[i][j]]++;
                }
            }
        }

        int y0 = freqsY[1]+freqsY[2];
        int y1 = freqsY[0]+freqsY[2];
        int y2 = freqsY[0]+freqsY[1];
        
        int noty0 = freqsNonY[1]+freqsNonY[2];
        int noty1 = freqsNonY[0]+freqsNonY[2];
        int noty2 = freqsNonY[0]+freqsNonY[1];

        int ans [] = new int [6];
        ans[0] = y0 +noty1;//01
        ans[1] = y1 + noty0;//10
        ans [2] = y1 +noty2;//12
        ans [3] = y2 +noty1;//21
        ans [4] = y2 +noty0;//20
        ans [5] = y0 +noty2;//02

        int res = Integer.MAX_VALUE;
        for(int i :ans) res = Math.min(i,res);
        return res;
    }
}