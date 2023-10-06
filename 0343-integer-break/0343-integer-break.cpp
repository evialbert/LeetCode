class Solution {
public:
    
    int call(int n,vector<int> &dp)
    {
        if(n==2)
            return 2;
        if(dp[n]!=-1)
            return dp[n];
        int INT_BREK =0 , f ;
        for(int i=n-1;i>=2;i--)
        {
            f = call(i,dp);
            f *= (n-i);
            INT_BREK = max(INT_BREK,f);
        }
        
        dp[n] = max(n,INT_BREK);   
        return INT_BREK;
        
            
    }
    
    int integerBreak(int n) {
        
        if(n==2)
            return 1;
        vector<int> dp(n+1,-1);
        int ans = call(n,dp);
        return ans;
        
        
    }
};