class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int n = nums.length;
        if(n==1) {
            return 0;
        }
        
        for(int i=1; i<n; i++) {
            if(nums[i]<=nums[i-1]) {
                int difference = nums[i-1] - nums[i] + 1;
                ans+= difference;
                nums[i] += difference;
            } 
        }
        return ans;
    }
}
