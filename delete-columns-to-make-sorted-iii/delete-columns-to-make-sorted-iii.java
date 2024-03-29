class Solution {
    public int minDeletionSize(String[] strs) {
        //0-current-delete,1-current-kept;
        int n=strs[0].length();
        int dp[][]=new int[n+1][2];
        for(int i=1;i<=n;i++){
            dp[i][0]=1+Math.min(dp[i-1][0],dp[i-1][1]);
            int j,min=i-1;
            for(j=i-1;j>0;j--){
                boolean lexico=true;
                for(String str : strs)if(str.charAt(i-1)<str.charAt(j-1)){
                    lexico=false;
                    break;
                }
                if(lexico)min=Math.min(min,dp[j][1]+i-j-1);
            }
            dp[i][1]=min;
        }
        return Math.min(dp[n][0],dp[n][1]);
    }
}