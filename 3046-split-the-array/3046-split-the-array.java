class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        int arr[] = new int[101];
         for(int i=0;i<nums.length;i++){
             arr[nums[i]]++;
         }
        for(int i : arr){
            if(i>2){
                return false;
            }
        }
        return true;
    }
}