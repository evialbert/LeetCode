class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;

        // First increasing sequence must exist
        if (nums[1] <= nums[0]) return false;

        int i = 2;
        
        // First strictly increasing phase
        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == n) return false;

        // Strictly decreasing phase
        while (i < n && nums[i] < nums[i - 1]) i++;
        if (i == n) return false;

        // Final strictly increasing phase
        for (int k = i; k < n; k++) {
            if (nums[k] <= nums[k - 1]) return false;
        }

        return true;
    }
}