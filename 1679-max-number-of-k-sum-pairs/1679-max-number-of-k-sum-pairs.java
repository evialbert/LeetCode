class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int start = 0, end = nums.length-1;
        int count = 0;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum == k){
                count++;
                start++;
                end--;
            }else if(sum < k){
                start++;
            }else{
                end--;
            }
        }
        return count;
    }
}