class Solution {
    public long maximumTotalCost(int[] nums) {
        long res1=nums[0],res2=nums[0];
        for(int i=1;i<nums.length;i++){
            long temp1=res1+nums[i];
            temp1=Math.max(temp1,res2+nums[i]);
            long temp2=res1-nums[i];
            res1=temp1;
            res2=temp2;
        }
        return Math.max(res1,res2);
    }
}