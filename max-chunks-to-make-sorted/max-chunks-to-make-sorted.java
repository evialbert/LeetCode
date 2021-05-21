class Solution {
    public int maxChunksToSorted(int[] nums) {
        int max=Integer.MIN_VALUE;
        int count=0;
        
        for(int i=0;i<nums.length;i++){
            max=Math.max(max,nums[i]);
            
            if(i==max) count++;
        }
        return count;
    }
}