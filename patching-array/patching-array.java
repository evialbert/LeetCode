class Solution {
    public int minPatches(int[] nums, int n) {
        if (nums == null) return 0;
		
		long sum = 0;
        int cnt = 0;
		for (int idx = 0; idx < nums.length || sum < n; idx ++) {
			long limit = (idx < nums.length) ? Math.min(nums[idx] - 1, n) : n;
			while (sum < limit) {
				sum += sum + 1;
				cnt ++;
			}
			if (idx < nums.length) sum += nums[idx];
		}
        
		return cnt;
    }
}