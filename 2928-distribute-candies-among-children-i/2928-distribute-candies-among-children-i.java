class Solution {
    public int solve(int n,int limit,int i)
    {
        if(i==3)
        {
            if(n==0)
            {
                return 1;
            }
            return 0;
        }
        int ans=0;
        for(int candi=0;candi<=Math.min(n,limit);candi++)
        {
            ans+=solve(n-candi,limit,i+1);
        }
        return ans;
    }
    public int distributeCandies(int n, int limit) {
        return solve(n,limit,0);
    }
}