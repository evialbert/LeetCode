class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n<=4) {
            return 0;
        }
        Arrays.sort(nums);
        int ans = Integer.MAX_VALUE;
        // numbers ranges in [0, n-4]
        ans = Math.min(ans, nums[n-4]-nums[0]);
        
        // numbers ranges in [1, n-3]       
        ans = Math.min(ans, nums[n-3]-nums[1]);
        
        // numbers ranges in [2, n-2]
        ans = Math.min(ans, nums[n-2]-nums[2]);
        
        // numbers ranges in [3, n-1]
        ans = Math.min(ans, nums[n-1]-nums[3]);
        return ans;
    }
}