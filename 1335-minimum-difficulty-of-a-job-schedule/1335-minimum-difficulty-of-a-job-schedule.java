class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(jobDifficulty.length < d) return -1 ;
        int[][] dp = new int[11][301];
        for(int[] a : dp){
            Arrays.fill(a,-1);
        }
        return solve(jobDifficulty , d , 0, dp);
    }
    
    public int solve(int[] n , int d , int index, int[][] dp){
        
        if(d==1) {
            int maxAns = Integer.MIN_VALUE;
            
            for(int i = index ; i<n.length ; i++){
                maxAns = Math.max(maxAns,n[i]);
            }
            return maxAns ;
        }
        
        if(dp[d][index] != -1) return dp[d][index];
        
        int maxAns = Integer.MIN_VALUE ;
        int finalresult = Integer.MAX_VALUE ;
        
        for(int i = index ; i<=n.length - d ; i++){
            maxAns = Math.max(maxAns,n[i]);
            int result = maxAns + solve(n,d-1,i+1,dp) ;
            finalresult = Math.min(finalresult,result);
        }
        
        return dp[d][index] = finalresult ;
    }
}