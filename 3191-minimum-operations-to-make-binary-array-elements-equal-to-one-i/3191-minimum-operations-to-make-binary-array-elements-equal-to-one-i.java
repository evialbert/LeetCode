class Solution {
    public int minOperations(int[] nums) {
        int count = 0;
        int i = 0;
        while (i < nums.length) {
            if (nums[i] == 0) {
                if (i + 2 < nums.length) {
                    for (int j = i; j < i + 3; ++j) {
                        nums[j] = 1 - nums[j];
                    }
                    count++;
                } else {
                    return -1;
                }
            }
            i++;
        }
        return count;
    }
}
