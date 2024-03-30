class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int count = Integer.MAX_VALUE;
        for(int i = 0;i<nums.length;i++){
            int total = 0;
            for(int j = i;j<nums.length;j++){
                total = total | nums[j];
                if(total >= k){
                    count = Math.min(count, j - i + 1);
                }
            }
        }
        return count == Integer.MAX_VALUE ? -1 : count;
    }
}