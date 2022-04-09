class Solution {
    public int minOperations(int[] nums, int x) {
        // problem reduction:
        // find the max len of subarray with sum of **(total of nums - x)**
        
        int total = 0;
        for (int num: nums) {
            total += num;
        }
        
        int target = total - x;
        
        if (target == 0) {
            return nums.length;
        }
        
        int maxLen = 0;
        int sum = 0;
        
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            sum += nums[j];
            if (sum >= target) {
                while (sum > target && i < j) {
                    sum -= nums[i];
                    i++;
                }
                if (sum == target) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        
        if (maxLen == 0) {
            return - 1;
        } else {
            return nums.length - maxLen;
        }
    }
}