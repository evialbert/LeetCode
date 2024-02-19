class Solution {
    public int maxOperations(int[] nums) {
        int dp[][] = new int[nums.length][nums.length];
        int a = helper(2,nums.length-1,nums,nums[0]+nums[1],dp);
        int b = helper(0,nums.length-3,nums,nums[nums.length-2]+nums[nums.length-1],dp);
        int c = helper(1,nums.length-2,nums,nums[0]+nums[nums.length-1],dp);
        return 1+Math.max(a,Math.max(b,c));
    }
    int helper(int l,int r,int nums[],int sum,int dp[][]){
        if(l>=r)
            return 0;
        if(dp[l][r]!=0)
            return dp[l][r];
        int s1 = nums[l]+nums[l+1];
        int s2 = nums[r]+nums[r-1];
        int s3 = nums[l]+nums[r];
        int a=0;
        if(s1==sum){
            a = Math.max(a,helper(l+2,r,nums,sum,dp)+1);
        }
        if(s2==sum){
            a = Math.max(a,helper(l,r-2,nums,sum,dp)+1);
        }
        if(s3==sum){
            a = Math.max(a,helper(l+1,r-1,nums,sum,dp)+1);
            
        }
        dp[l][r] = a;
        return a;
    }
    
    
}