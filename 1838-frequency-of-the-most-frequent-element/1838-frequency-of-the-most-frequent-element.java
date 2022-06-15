class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        
        int start = 0;
        int leftSum = 0;
        int res = 1;
        
        for(int i=0; i<nums.length; i++){
            int length = i - start + 1;
            int product = nums[i] * length;
            leftSum += nums[i];
            while(product - leftSum > k){
                leftSum -= nums[start++];
                length--;
                product = nums[i] * length;
            }
            res = Math.max(res, length);
        }
        return res;
    }
}