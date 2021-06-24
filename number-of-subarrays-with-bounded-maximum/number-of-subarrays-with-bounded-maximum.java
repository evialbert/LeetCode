class Solution {
    
    public int countSubarray (int[] nums, int bound) {
        
        int answer = 0, count = 0;
        
        for (int num : nums) {
            count = num <= bound ? count + 1 : 0;
            answer += count;
        }
        
        return answer;
    }
    
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        
        return countSubarray (nums, right) - countSubarray (nums, left - 1);
    }
}