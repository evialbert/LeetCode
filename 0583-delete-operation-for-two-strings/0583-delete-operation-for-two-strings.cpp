class Solution {
public:
    int minDistance(string str1, string str2) {
        int n=str1.size();
	    int m=str2.size();
	    int dp[n+1][m+1];
	    for(int i=0; i<=n; i++)
	    {
	        for(int j=0; j<=m; j++)
	        {
	            if(j==0||i==0)
	            dp[i][j]=0;
	            
	        }
	    }
	     for(int i=1; i<=n; i++)
	     {
	        for(int j=1; j<=m; j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	            
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	                else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	            
	            
	        }
	     }
	     
	     int ans=n+m-2*dp[n][m];
	     return ans;
	     
    }
};