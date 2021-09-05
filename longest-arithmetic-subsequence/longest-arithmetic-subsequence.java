//Java short solution O(n^2) time O(n) space
class Solution {
   public int longestArithSeqLength(int[] nums) {
        int[][] largestSubs = new int[nums.length][1001];
        int maxFound = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int diff = nums[j] - nums[i] + 500;
                largestSubs[i][diff] = Math.max(largestSubs[j][diff] + 1,
                                                largestSubs[i][diff]);
                maxFound = Math.max(maxFound, largestSubs[i][diff]);
            }
        }
        return maxFound + 1;
    }
}
