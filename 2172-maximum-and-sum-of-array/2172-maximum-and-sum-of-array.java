class Solution {
    public int trav(int nums[],int index,int n,int b1,int b2,int dp[][])
    {
        if(index>=nums.length)
            return 0;
        if(dp[b1][b2]>0)
            return dp[b1][b2];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if((b1&(1<<i))==0)
                ans=Math.max(ans,(nums[index]&i)+trav(nums,index+1,n,b1|(1<<i),b2,dp));
            else
            {
                if((b2&(1<<i))==0)
                    ans=Math.max(ans,(nums[index]&i)+trav(nums,index+1,n,b1,b2|(1<<i),dp));
            }
        }
        return dp[b1][b2]=ans;
    }
    public int maximumANDSum(int[] nums, int numSlots) {
        int n=(1<<(numSlots+1));
        int dp[][]=new int[n+1][n+1];
        return trav(nums,0,numSlots,0,0,dp);
    }
}