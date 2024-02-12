class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int result = 0;
        for (int i = 0; i < nums.length - pattern.length; i++) {
            boolean matches = true;
            for (int j = 0; j < pattern.length; j++) {
                int index = i + j;                
                int num1 = nums[index];
                int num2 = nums[index + 1];
                if (num2 > num1 && pattern[j] != 1) {
                    matches = false;
                }
                if (num2 == num1 && pattern[j] != 0) {
                    matches = false;
                }
                if (num1 > num2 && pattern[j] != -1) {
                    matches = false;
                }
            }
            if (matches) {
                result++;
            }
        }
        return result;
    }
}