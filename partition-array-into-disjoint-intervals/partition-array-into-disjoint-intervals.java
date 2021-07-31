class Solution {
    public int partitionDisjoint(int[] nums) {
        int[] min = new int[nums.length];
        min[nums.length-1] = nums[nums.length-1];
        
        int minVal = nums[nums.length-1];
        for(int i = nums.length-2;i>=0;i--)
        {
            minVal = Math.min(minVal, nums[i]);
            min[i] = minVal;
        }
        
        int maxVal = nums[0];
        for(int i = 0;i<nums.length-1;i++)
        {
            maxVal = Math.max(maxVal, nums[i]);
            if(maxVal <= min[i+1])
                return i+1;
        }
        return 0;
        
    }
}