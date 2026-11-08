class Solution {
    public long maxSum(int[] nums, int k, int mul) {
        Arrays.sort(nums);
        long sum = 0;
        int n = nums.length-1;
        while(k > 0){
            if(mul > 0){
                sum += 1L * nums[n] * mul; 
            }else {
                sum += nums[n];
            }
            n--;
            k--;
            mul--;
        }
        return sum;
    }
}