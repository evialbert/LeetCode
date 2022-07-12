class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] ans = new int[nums.length];
        Arrays.sort(nums);

        for(int i=0,j=nums.length-1,k=0;i<=j;k++){
            ans[k] = (k&1)==0?nums[j--]:nums[i++];
        }
        return ans;
    }
}