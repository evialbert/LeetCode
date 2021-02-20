public class NumArray {
    private int[] dp;
    public NumArray(int[] nums) {
        
        if(nums.length==0){
            return;
        }
        dp = new int[nums.length];
        
        dp[0] = nums[0];
        for(int i=1;i<nums.length;i++){
            dp[i] = dp[i-1]+nums[i];
        }
        
    }
    
    public int sumRange(int i, int j) {
        if(i==0) return dp[j];
        
        return dp[j]-dp[i-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */