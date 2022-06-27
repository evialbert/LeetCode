class Solution {
    public boolean canBeIncreasing(int[] nums) {
        if(nums==null||nums.length<1) return true;
        boolean flag =false;
        int pre=0;
        for(int i=1;i<nums.length;i++){
            if(nums[i] <= nums[i-1]){
                if(flag) return false;
                flag = true;
                if(i>=2&&nums[i-2]<nums[i]){
                    pre = nums[i];
                }else if(i==1&&nums[i-1]>nums[i]){
                    pre = nums[i];
                }else{
                    pre = nums[i-1];
                }
                
            }else if(flag){
                if(nums[i]<=pre) return false;
                pre = nums[i];
            }
        }
        
        return true;
    }
}