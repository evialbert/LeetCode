class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] dp=new int[n];
        dp[0]=1;
        int[] v=new int[primes.length];
        for(int i=1;i<n;i++)
        {
            int next=Integer.MAX_VALUE;
            for(int j=0;j<primes.length;j++)
                next=Math.min(next,dp[v[j]]*primes[j]);
            dp[i]=next;
            for(int j=0;j<primes.length;j++)
            {
                if(dp[v[j]]*primes[j]==next)
                    v[j]++;
            }
                
        }
        return dp[n-1];
    }
}