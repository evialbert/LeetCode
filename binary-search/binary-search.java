class Solution {
    public int search(int[] nums, int target) {
         if(nums == null || nums.length == 0){
              return -1;
          }
          
          int l = 0;
          int r = nums.length-1;
          while(l <= r){
            int mid = l + (r-l)/2;
             if(nums[mid] < target){
                 l = mid + 1;
            }else if(nums[mid] > target){
                 r = mid-1;
             }else{
                 return mid;
            }
        }         
         return -1;
     }
 }
