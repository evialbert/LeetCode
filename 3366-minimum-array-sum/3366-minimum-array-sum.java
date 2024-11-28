class Solution {
    public int minArraySum(int[] nums, int k, int op1, int op2) {
        int n = nums.length;
        int[][][] dp = new int[n + 1][op1 + 1][op2 + 1];

        for(int[][] row : dp) {
            for(int[] col : row) {
                Arrays.fill(col, -1);
            }
        }

        
        return f(nums, k, op1, op2, 0, dp);
    }

    private int f(int[] nums, int k, int op1, int op2, int index,int[][][] dp) {
        if(index >= nums.length) {
            return 0;
        }

        if(dp[index][op1][op2] != -1) return dp[index][op1][op2];

        int ele = nums[index];

        int sum = ele + f(nums, k, op1, op2, index + 1, dp);
        if(op1 > 0) {
            int val = (nums[index] + 1) / 2;
            sum = Math.min(sum, val + f(nums, k, op1 -1, op2, index + 1, dp));
        }

        if(op2 > 0 & nums[index] - k >= 0) {
            int val = nums[index] - k;
            sum = Math.min(sum, val + f(nums, k, op1, op2 -1 , index + 1, dp));
        }

        if(op1 > 0 && op2 > 0 && nums[index] - k >= 0) {
            int val =(nums[index] + 1) / 2;
            if(val - k >= 0){
                val = val - k;
                sum = Math.min(sum, val + f(nums, k, op1 -1, op2 -1, index + 1, dp));
            }
            val =  (nums[index] - k + 1) / 2;
            sum = Math.min(sum, val + f(nums, k, op1 -1, op2 -1, index + 1, dp));
            
        }

        return dp[index][op1][op2] = sum;
        
    }
}