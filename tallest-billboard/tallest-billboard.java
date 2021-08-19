class Solution {
    int[][] dp;
    // HashMap<String, Integer> dp;
    int n, ar[], sum;
    public int tallestBillboard(int[] rods) {
        sum =0;
        n = rods.length;
        ar = rods;
        for(int i:rods){
            sum+=i;
        }
        // dp  =new HashMap<>();
        // System.out.println(sum*sum*n);
        dp = new int[n][2*sum+5];
        for(int i=0;i<n;i++){
            for(int j=0;j<2*sum+5;j++){
                dp[i][j] = -1;
            }
        }
        
        return dfs(0,0)/2;
    }
    int dfs(int idx, int diff){
        if(idx==n){
            if(diff==0){
                return 0;
            }
            return Integer.MIN_VALUE;
        }
        if(dp[idx][diff+sum]!=-1){
            return dp[idx][diff+sum];
        }
        
        int a = dfs(idx+1, diff);
        int b = ar[idx]+dfs(idx+1, diff+ar[idx]);
        int c = ar[idx]+dfs(idx+1, diff-ar[idx]);
        
        return dp[idx][diff+sum] = Math.max(a,Math.max(b,c));
    }
}