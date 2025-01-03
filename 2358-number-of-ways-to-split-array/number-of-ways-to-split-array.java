class Solution {
    public int waysToSplitArray(int[] nums) {
        long sum = 0;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
        }
        int count = 0;
        long val = nums[0];
        for(int i=0;i<nums.length-1;i++){
            if(val >= sum-val){
                count++;
            }
            val += nums[i+1];
        }
        return count;
    }
}