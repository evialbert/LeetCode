class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        int min = Integer.MAX_VALUE;
        
        for(int val : nums){
            min = Math.min(val, min);
        }
        if(min < k) return -1;
        
        int count = 0;
        
        Arrays.sort(nums);
        for(int i=n-2;i>=0;i--){
            if(nums[i] != nums[i+1]){
                for(int j=i+1;j<n;j++){
                    nums[j] = nums[i];
                }
                count++;
            }
        }
        
        if(nums[0] != k){
            count++;
        }
        
        return count;
    }
}