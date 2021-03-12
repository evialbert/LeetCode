class Solution {
    public int splitArray(int[] nums, int m) {
        int l = 0;
        int r =(int)Math.pow(10, 9)+1;
        while(l<r){
           int mid = l+(r-l)/2;
            if(isPossible(nums,m, mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    public boolean isPossible(int[] nums, int m, int mid){
        int subArrCnt = 0;
        int target = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>mid)
                return false;
            if(nums[i]+target<=mid){
                target+=nums[i];
            }else{
                subArrCnt++;
                target = nums[i];
            }
        }
        subArrCnt++;
        return subArrCnt<=m;
    }
}