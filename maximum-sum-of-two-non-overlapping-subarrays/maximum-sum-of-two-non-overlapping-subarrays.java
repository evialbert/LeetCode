class Solution {
    // this technique is based on finding max sum from left and right for both first and second len
    // then find combination which produce max sum
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int ans = 0;
        int[] right = maxSumFromRight(nums, secondLen);
        int[] left = maxSumFromLeft(nums, firstLen);
        for(int i = 0; i < nums.length - 1; i++) {
            ans = Math.max(left[i] + right[i + 1], ans);
        }
  
        right = maxSumFromRight(nums, firstLen);
        left = maxSumFromLeft(nums, secondLen);
        for(int i = 0; i < nums.length - 1; i++) {
            ans = Math.max(left[i] + right[i + 1], ans);
        }
    
        return ans;
    }
    
    public int[] maxSumFromRight(int[] nums, int len) {
        int n = nums.length;
        int[] right = new int[n];
        int max = 0;
        for(int i = n - 1; i >= len - 1; i--) {
            int sum = 0;
            for(int j = i; j > i - len; j--) sum += nums[j];
            max = Math.max(max, sum);
            right[i - len + 1] = max;
        }
        
        return right;  
    }
    
    public int[] maxSumFromLeft(int[] nums, int len) {
        int n = nums.length;
        int[] left = new int[n];
        int max = 0;
        for(int i = 0; i <= n - len; i++) {
            int sum = 0;
            for(int j = i; j < i + len; j++) sum += nums[j];
            max = Math.max(max, sum);
            left[i + len - 1] = sum;
        }
        return left;
    }
}