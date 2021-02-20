class Solution {
   public boolean containsDuplicate(int[] nums) {
    		int i = 0;
    		HashSet<Integer> hs = new HashSet();
    		while (i < nums.length){
        		if(!hs.contains(nums[i])){
            			hs.add(nums[i]);
            			i++;
   			} else {
   				return true;
    			}
    		}
    		return false;
	}

}