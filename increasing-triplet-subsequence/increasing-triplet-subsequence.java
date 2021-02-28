class Solution {
   public boolean increasingTriplet(int[] nums) {
	    if(nums == null || nums.length < 3) return false;
		int one = Integer.MAX_VALUE, two = Integer.MAX_VALUE;

		for (int num : nums) {
			if (num < one) {
				one = num;
			} else if (num > one && num < two) {
				two = num;
			} else if (num > two) {
				return true;
			}
		}
		return false;
	}
}