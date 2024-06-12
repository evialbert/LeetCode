class Solution {
    public void sortColors(int[] nums) {
        if(nums.length<2)   return;
        int low = 0;
        int high = nums.length-1;

        int i=0;

        while(i<=high){

            if(nums[i]==0){
                if(nums[low]==0){
                    low++;
                    i=low;
                }else{
                    nums[i] = nums[low];
                    nums[low] = 0;
                    low++;
                }
                
            }else if(nums[i]==1){
                i++;
                continue;
            }else{
                if(nums[high]==2){
                    high--;
                }else{
                    nums[i] = nums[high];
                    nums[high--] = 2;
                }
            }
        }
    }
}