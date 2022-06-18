class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        
        // Time Complexity - O(n)
        int n = nums.length;
        int leftIndex = Integer.MAX_VALUE;
        int rightIndex = Integer.MAX_VALUE;

        for(int i = start-1; i>=0; i--){
            if(nums[i] == target){
                leftIndex = start-i;
                break;
            }
        }
        
        for(int i = start; i<n; i++){
            if(nums[i] == target){
                rightIndex = i-start;
                break;
            }
        }
        
        return Math.min(leftIndex, rightIndex);
    }
}