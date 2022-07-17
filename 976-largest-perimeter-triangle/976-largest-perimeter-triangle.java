class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length,max=0;
        for(int i=n-1;i>1;i--){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return Math.max(max,nums[i]+nums[i-1]+nums[i-2]);
            }
        }
        return max;
    }
}