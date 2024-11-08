class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        List<List<Integer>> result = new ArrayList<>();
        
        Arrays.sort(nums);
        
        backtrack(result, nums, new ArrayList<>(), 0);
        
        return result;
    }
    
    private void backtrack(List<List<Integer>> result, int[] nums, List<Integer> subset, int idx)
    {
        result.add(new ArrayList<>(subset));
        
        Set<Integer> visited = new HashSet<>();
        
        for (int i = idx; i < nums.length; i++)
        {
            if (visited.add(nums[i]))
            {
                subset.add(nums[i]);
                backtrack(result, nums, subset, i+1);
                subset.remove(subset.size()-1);
            }
        }
    }  
}