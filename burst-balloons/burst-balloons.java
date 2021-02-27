class Solution {
    public int maxCoins(int[] nums) {
        
        if(nums.length == 0){
            return 0;
        }
        
        int[][] dp = new int[nums.length][nums.length];
        
        for(int g = 0; g < dp.length; g++){
            for(int i = 0,j = g; j < dp.length; i++,j++){
                int max = Integer.MIN_VALUE;
                for(int k = i; k <= j; k++){
                    int left = (i == k) ? 0 : dp[i][k-1];
                    int right = (k == j) ? 0 : dp[k+1][j];
                    int val = (i == 0 ? 1 : nums[i-1]) * nums[k] * (j == nums.length - 1 ? 1 :nums[j+1]);
                    int total = left + right + val;
                    max = Math.max(max,total);
                    }
                dp[i][j] = max;
            }
        }
        return dp[0][dp.length - 1];
    }
}