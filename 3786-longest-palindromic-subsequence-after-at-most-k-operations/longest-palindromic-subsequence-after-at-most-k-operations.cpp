class Solution {
public:
    int solve(string& s, int k , int i, int j, vector<vector<vector<int>>>& dp){
        if(i==j){return 1;}
        if(i>j){return 0;}
        if(dp[i][j][k]!=-1){return dp[i][j][k];}
        int take = INT_MIN, nottake = INT_MIN;
        int diff = min(abs(s[i]-s[j]), 26-abs(s[i]-s[j]));
        // if(diff==25){diff=1;}
        if(diff<=k){
            take = 2 + solve(s,k-diff,i+1,j-1,dp);
        }
        nottake = max(solve(s,k,i+1,j,dp),solve(s,k,i,j-1,dp));
        return dp[i][j][k] = max(take,nottake);
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(s,k,0,n-1,dp);
    }
};