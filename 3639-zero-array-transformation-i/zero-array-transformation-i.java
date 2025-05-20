class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] freq = new int[n + 1];
        for (int[] q : queries){
            freq[q[0]] += 1;
            freq[q[1] + 1] -= 1;
        }
        int rsum = 0;
        for (int i = 0; i < n; i++){
            rsum += freq[i];
            freq[i] = rsum;
            if (freq[i] < nums[i]){
                return false;
            }
        }
        return true;
    }
}