class Solution {
   public int minSwaps(int[] nums) {
		int len = nums.length;
		int totalOne = 0;

		for (int i = 0; i < len; i++) {
			if (nums[i] == 1)
				totalOne++;
		}
		if (len == totalOne || totalOne == 0)
			return 0;
		int min = Integer.MAX_VALUE;
		int i = 0;
		int count = 0;
		for (int k = i; k < totalOne; k++) {
			if (nums[k] == 0)
				count++;
		}
		min = Math.min(min, count);
		i++;
		for (; i < len; i++) {
			int j = (i + totalOne - 1) % len;
			if (nums[j] == 0 && nums[i - 1] == 1)
				count++;
			else if (nums[j] == 1 && nums[i - 1] == 0)
				count--;
			min = Math.min(min, count);
		}
		return min;
	}
}