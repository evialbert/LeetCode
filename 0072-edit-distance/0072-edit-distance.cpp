class Solution {
public:
    // tabulation:
    int minDistance(string a, string b) {
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        // base:
        for(int j=0;j<=m;++j) dp[0][j]=j; //1 based indexing
        for(int i=0;i<=n;++i) dp[i][0]=i;
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(a[i-1]==b[j-1]) dp[i][j]= 0 + dp[i-1][j-1];
                 else{
                     // not matched so perform 3 op's and take min of it
                    int insert=1+dp[i][j-1];
                    int delet=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];

                    dp[i][j]=min({insert,delet,replace});
                 }
                
            }
        }
        return dp[n][m];
    }
};