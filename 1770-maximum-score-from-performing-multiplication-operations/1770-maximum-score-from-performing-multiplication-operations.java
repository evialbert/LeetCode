class Solution {
    int[][] dp = new int[1000][1000];
public int maximumScore(int[] nums, int[] multipliers) {
   return helper(nums,multipliers,0,nums.length-1,0); 
}

public int helper(int a[],int[] b,int start,int end,int mindex)
{
    
    if(mindex==b.length) return 0;
    if(dp[mindex][start]!=0) return dp[mindex][start];
    int val1=b[mindex]*a[start]+helper(a,b,start+1,end,mindex+1);
    int val2=b[mindex]*a[end]+helper(a,b,start,end-1,mindex+1);
    dp[mindex][start]=Math.max(val1,val2);
   return dp[mindex][start];   
 }
}