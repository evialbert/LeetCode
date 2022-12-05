class Solution {
public:
    int mod=1e9+7;
    int countTexts(string &s) 
    {
        int n=s.size();
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1];
            if(s[i]==s[i-1])
                dp[i]=i>1?(dp[i]+dp[i-2]):(dp[i]+1);
            dp[i]%=mod;
            if(i>1 && s[i]==s[i-1] && s[i]==s[i-2])
                dp[i]=i>2?(dp[i]+dp[i-3]):(dp[i]+1);
            dp[i]%=mod;
            if(i>2 && (s[i]=='7' || s[i]=='9') && s[i]==s[i-1] && s[i]==s[i-2] && s[i]==s[i-3])
                dp[i]=i>3?(dp[i]+dp[i-4]):(dp[i]+1);
            dp[i]%=mod;
        }
        return dp[n-1];
    }
};