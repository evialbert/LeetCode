class Solution {
    public int findMin(int[] nums) {
        int previous = nums[0];
        for(int i = 1; i < nums.length; i++){
            if(previous > nums[i]){
                return nums[i];
            }
        }
        return nums[0];
    }
}