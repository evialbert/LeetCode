class Solution {
    public int dominantIndices(int[] nums) {

        int ans = 0;
        int count = 0;

        for(int i = nums.length-2 ; i>=0 ;i--){
            count++;
            float average =(float)nums[i+1] / count;
            if(nums[i] > average){
                ans++;
            }
            nums[i] += nums[i+1];  
        }

        return ans;
    }
}