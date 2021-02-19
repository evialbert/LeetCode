class Solution {
    public int findDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        
        int n = nums.length, start = 1, end = n; // as given, the [start, end] is in [1, n]
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (validate(mid, nums)) start = mid;
            else end = mid;
        }
        
        return validate(start, nums) ? end : start;
    }
    
    private boolean validate(int candidate, int[] nums) {
        int count = 0;
        for (int num: nums) {
            count += num <= candidate ? 1 : 0;
        }
        return count <= candidate;
    }
}