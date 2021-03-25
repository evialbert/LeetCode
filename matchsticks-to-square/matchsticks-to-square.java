class Solution {
    public boolean makesquare(int[] nums) {

        if(nums.length==0) return false;
        
		int sum = 0;

		for (int num : nums) {
			sum = sum + num;
		}

		if (sum % 4 != 0)
			return false;

		int target = sum / 4;
        
        Arrays.sort(nums);

		return dfs(nums, 0, 0, target, new boolean[nums.length], 1);

	}

	public boolean dfs(int[] nums, int pos, int tmpsum, int target, boolean[] visited, int grpId) {

		if (grpId == 4)
			return true;
		if (tmpsum > target)
			return false;
		if (tmpsum == target) {

			if (dfs(nums, 0, 0, target, visited, grpId + 1))
				return true;

		}

		for (int i = 0; i < nums.length; i++) {
			if (visited[i])
				continue;

            if(i>0 && nums[i]==nums[i-1] && !visited[i-1] ) continue;
            
			visited[i] = true;
			if (dfs(nums, 0, tmpsum + nums[i], target, visited, grpId)) {
				return true;
			}
			visited[i] = false;
		}

		return false;

	}
}