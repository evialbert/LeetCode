class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum % k != 0){
            return false;
        }
        sum /= k;
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, k, sum, 0, 0, visited);
    }
    public boolean dfs(int[] nums, int k, int target, int sum, int index, boolean[] visited){
        if(k == 0){
            return true;
        }
        if(sum > target){
            return false;
        }
        if(sum == target){
            return dfs(nums, k - 1, target, 0, 0, visited);
        }
        for(int i = index; i < nums.length; i++){
            if(!visited[i]){
                sum += nums[i];
                visited[i] = true;
                if(dfs(nums, k, target, sum, i + 1, visited)){
                    return true;
                }
                sum -= nums[i];
                visited[i] = false;
            }
        }
        return false;
    }
}