class Solution {
   
    Set<List<Integer>> set = new HashSet<>();
    int visited[] = null;
    
    public List<List<Integer>> permuteUnique(int[] nums) {
       
        visited = new int[nums.length];
        helper(nums, new ArrayList<Integer>());
       
        return new ArrayList<>(set);
        
    }
    
    private void helper(int[] nums, List<Integer> list){
         if(list.size()==nums.length){
           set.add(new ArrayList<>(list)); 
             return;
         }
      
        for(int i=0; i<nums.length; i++){    

            if(visited[i] == 0){
                list.add(nums[i]);
                visited[i] = 1;
                helper(nums, list);
                list.remove(list.size()-1);
                visited[i] = 0;
            }

             
        }
        
        
    }
    
}