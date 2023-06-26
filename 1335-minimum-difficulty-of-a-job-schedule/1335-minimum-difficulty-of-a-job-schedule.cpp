class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n+1,vector<int>(days+1,INT_MAX));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            int maxi=jobDifficulty[i-1];
            for(int j=i-1;j>=0;j--){
                for(int d=1;d<=days;d++)
                    if(dp[j][d-1]!=INT_MAX)
                        dp[i][d]=min(dp[i][d],dp[j][d-1]+maxi);
                
                if(j-1>=0)
                    maxi=max(maxi,jobDifficulty[j-1]);
            }
        }
        
        return dp[n][days]==INT_MAX?-1:dp[n][days];
    }
};