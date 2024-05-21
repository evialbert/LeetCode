class Solution {
    public List<List<Integer>> subsets(int[] nums) {
         List<List<Integer>>  ans   =  new ArrayList<List<Integer>>();
         helper(nums, ans, 0 , new ArrayList<Integer>());
         return ans;
      }
    private void helper(int[]nums, List<List<Integer>>  ans, int index, List<Integer> subList){
        ans.add(new ArrayList<>(subList));
        for(int i = index;i<nums.length;i++){
          subList.add(nums[i]);
          helper(nums,ans,  i+1, subList);     
          subList.remove(subList.size()-1);
        }
   }
}