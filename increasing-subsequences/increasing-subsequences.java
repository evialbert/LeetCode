class Solution {
    public void helper(Set<List<Integer>> ans, List<Integer> path, int start, int cur, int[] nums){
        if(start >= nums.length) return;
        for(int i=start; i<nums.length;i++){
             if(nums[i] >= cur){
                 path.add(nums[i]);
                 if(path.size()>=2) ans.add(new ArrayList<>(path));
                 helper(ans, path, i+1, nums[i], nums);
             }
            else if(nums[i]<cur) continue;
            path.remove(path.size()-1);
        }
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> ans= new HashSet<>();
        if(nums==null || nums.length==0) return new ArrayList<>();
        helper(ans, new ArrayList<>(), 0, -101, nums);
        return new ArrayList<>(ans);
    }
}