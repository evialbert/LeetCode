class Solution {
    public int findNumberOfLIS(int[] nums) {
        int dp[][] = new int[nums.length][2];
        int max = 1;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1;i<nums.length;i++){
            dp[i][0] = 1;
            dp[i][1] = 1;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[j][0]+1 >= dp[i][0]){
                    if(dp[j][0]+1 > dp[i][0]){
                        dp[i][0] = dp[j][0]+1;
                        dp[i][1] = dp[j][1];
                    }else{
                        dp[i][1] += dp[j][1];
                    }       
                }
            }
            max = Math.max(max,dp[i][0]);
        }
        int res = 0;
        for(int i=0;i<nums.length;i++){
            if(dp[i][0] == max)
                res += dp[i][1]; 
            
        }
        return res;
    }
}
