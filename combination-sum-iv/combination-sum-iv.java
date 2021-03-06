class Solution {
    int[] dp = null;
    public int combinationSum4(int[] nums, int target) {
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp == null){
            dp = new int[target+1];
            Arrays.fill(dp, -1);
        }
        if(dp[target] != -1)
            return dp[target];
        int res = 0;
        for(int num : nums){
            res += combinationSum4(nums, target-num);
        }
        dp[target] = res;
        return res;
    }
}