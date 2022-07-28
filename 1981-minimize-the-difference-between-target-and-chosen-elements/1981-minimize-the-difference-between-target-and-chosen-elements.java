class Solution {
    int[][] dp;
    public int minimizeTheDifference(int[][] mat, int target) {
        int n = mat.length , m = mat[0].length;
        
        dp = new int[n][5000];
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < 5000 ; j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        return solve(mat , 0 , 0 , target , n , m);
    }
    
    int solve(int[][] arr , int i , int curr , int target , int n , int m){
        if(i == n){
            return Math.abs(target - curr);
        }
        
        if(dp[i][curr] != Integer.MAX_VALUE) return dp[i][curr];
        
        int min = Integer.MAX_VALUE;
        
        for(int k = 0 ; k < m ; k++){
            min = Math.min(min , solve(arr , i+1 ,curr + arr[i][k] , target , n , m));    
        }
        
        return dp[i][curr] = min;
        
    }
    
}