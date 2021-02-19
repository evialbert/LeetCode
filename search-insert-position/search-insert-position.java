class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target > nums[nums.length - 1]){
            return nums.length;
        }
        int l = 0;
        int r = nums.length - 1;
        
        while(l < r){
            int m = l + (r - l)/2;
            if(target > nums[m]){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return l;
    }
}