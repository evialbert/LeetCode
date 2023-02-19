class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
					if(s[i-1]==s[n-j])     //accesing the index value from the right(that is reverse format)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};