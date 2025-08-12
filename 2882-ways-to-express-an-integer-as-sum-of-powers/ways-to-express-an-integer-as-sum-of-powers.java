class Solution {
    private int mod=1_000_000_007;
    public int numberOfWays(int n, int x) {
        long[][] dp=new long[n+1][n+1];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            long curSum=(long)Math.pow(i,x);
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=curSum){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-(int)curSum])%mod;
                }
            }
        }
        return (int)dp[n][n];
    }
}