class Solution {
    public int dominantIndex(int[] nums) {
        int maxVal = 0;
        int secMax = 0;
        int idx = -1;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > maxVal){
                idx = i;
                secMax = maxVal;
                maxVal = nums[i];
            }else if(nums[i] > secMax){
                secMax = nums[i];
            }
        }
        return maxVal >= secMax * 2 ? idx : -1;
    }
}