class Solution {
    public boolean check(int[] nums) {
        if (checkOnlyNoDecreasing(nums)) return true;
        int index = 0;
        while (nums[index] <= nums[++index]){}
        for (int i = index; i < nums.length -1; i++) {
            if (nums[i+1] < nums[i]) return false;
        }
        return nums[nums.length -1] <= nums[0];
    }

    private boolean checkOnlyNoDecreasing(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i+1] < nums[i]) return false;
        }
        return true;
    }
}