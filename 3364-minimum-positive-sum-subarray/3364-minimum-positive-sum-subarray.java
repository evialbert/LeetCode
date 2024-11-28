class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int size = nums.size(), res = -1;
	for(int s=l; s<=r; s++) {
		for(int i=0; i<=size-s; i++) {
			int sum = 0;
			for(int j=i; j<i+s; j++) {
				sum += nums.get(j);
			}
			if(sum > 0) {
				if(res == -1 || res > sum) res = sum;
			}
		}
	}
	return res;
    }
}