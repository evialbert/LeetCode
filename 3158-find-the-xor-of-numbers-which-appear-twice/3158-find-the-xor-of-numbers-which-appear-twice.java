class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        
        Set<Integer> set = new HashSet<>();
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int i = 0 ; i < nums.length ; i++) {
            if(set.contains(nums[i])) {
                list.add(nums[i]);
            }
            set.add(nums[i]);
        }
       
        
        
         int xorResult = 0;
        for (Integer num :list ) {
            if(num!=-1)
            xorResult ^= num;
        }
        return xorResult;
    }
}