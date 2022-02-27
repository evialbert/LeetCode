class Solution {
	public int getMaxLen(int[] nums) {
		int L = nums.length,
		start = 0,
		  max = 0,
	   nCount = 0,
		 prev = -1;

		for(int end = 0;end < L;end++) {
			if(nums[end] == 0) {
				start = end+1;
				nCount = 0;
				prev = -1;
				continue;
			} else if(nums[end] < 0)
				++nCount;

			if(prev == -1 && nCount == 1 ) {
				prev = end + 1;
				continue;
			}

			if(nCount%2 == 0)
				max = Math.max(max, end - start + 1);
			else
				max = Math.max(max, end - prev + 1);
		}
		return max;
	}
}