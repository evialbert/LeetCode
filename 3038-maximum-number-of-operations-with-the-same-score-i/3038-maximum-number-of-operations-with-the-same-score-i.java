class Solution {
    public int maxOperations(int[] nums) {
        if(nums.length < 2) return 0;
        if(nums.length == 2) return 1;
        
        int count = 1;
        int score = nums[0] + nums[1];
        int i = 2;
        
        while(i < nums.length) {
            if(i+1 < nums.length && nums[i] + nums[i+1] == score) {
                count++;
                i += 2;
            } else {
                break;
            }
            
        }
        
        return count;
    }
}