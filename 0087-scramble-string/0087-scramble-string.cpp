class Solution {
public:
    bool isScramble(string s1, string s2) 
    {    
    
        int n = s1.length();
        int dp[31][31][31];
        for(int l=1;l<=n;l++)
        {
           for(int i=0;i+l-1<n;i++)
           {
               for(int j=0;j+l-1<n;j++)
               {
                   dp[l][i][j] = 0;
                   if(l == 1)
                       dp[l][i][j] = s1[i]==s2[j];
                   else
                   {
                        for(int k=1;k<l;k++)
                            dp[l][i][j] = dp[l][i][j] || ((dp[k][i][j] && dp[l-k][i+k][j+k]) || (dp[k][i+l-k][j] && dp[l-k][i][j+k])); 
                   }
               }
           }
        }
        return dp[n][0][0];
    
    }
};