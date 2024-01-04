class Solution {
    public int minOperations(int[] nums) {
        
        Arrays.sort(nums);
        Integer[] dp = new Integer[nums.length];
        int ans = function(0,nums,dp);
        if(ans>=(int) 1e8) return -1;
        return ans;
    }
    
    
    public int function(int ind,int[] nums,Integer[] dp){
        
        if(ind==nums.length) return 0;
        
        if(dp[ind]!=null) return dp[ind];
        
        int take_two = (int) 1e8;
        if(ind+1<nums.length && nums[ind]==nums[ind+1]){
            take_two = 1 + function(ind+2,nums,dp);
        }
        
        int take_three = (int) 1e8;
        if(ind+2<nums.length && nums[ind]==nums[ind+1] && nums[ind]==nums[ind+2]){
            take_three = 1 + function(ind+3,nums,dp);
        }
        
        return dp[ind]=Math.min(take_two,take_three);
    }    
}