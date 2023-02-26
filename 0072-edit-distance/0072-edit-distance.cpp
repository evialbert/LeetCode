class Solution {
public:
    int minDistance(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=0;i<=a.size();++i) dp[i][0]=i;
        for(int j=0;j<=b.size();++j) dp[0][j]=j;
        for(int i=1;i<=a.size();++i){
            for(int j=1;j<=b.size();++j){
                if(a[i-1]==b[j-1]) 
                    dp[i][j]=dp[i-1][j-1];
                else{
                    int cnt=INT_MAX;               
                    cnt=min(cnt,dp[i][j-1]+1);       //insert
                    cnt=min(cnt,dp[i-1][j-1]+1);     //replace
                    cnt=min(cnt,dp[i-1][j]+1);       //delete
                    dp[i][j]=cnt;
                }
            }
        }
        
    return dp[a.size()][b.size()];
    }
};