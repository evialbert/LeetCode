class Solution {
    public int maximumDifference(int[] nums) {
        int[] arr= new int[(nums.length)*nums.length];
        int diff=0,n=0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[j]>nums[i]){
                    diff=nums[j]-nums[i];
                }
                if(diff>0){
                    arr[n++]=diff;
                }
            }
        }
        int max=arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        if(diff<0 || diff==0) return -1;
        return max;
    }
}