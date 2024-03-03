class Solution {
    public int minOperations(int[] nums, int k) {

        Arrays.sort(nums);
        int left=0;
        int res =0;

        int right=nums.length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<k){
                res = res+(mid-left+1);
                left =mid+1;
            }else{
                right = mid-1;
            }
        }
        return res;
        
    }
}