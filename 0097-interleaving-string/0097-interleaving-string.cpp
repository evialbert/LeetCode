class Solution {
public:
    bool f(int i,int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        //base cases
        if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
        if(i>s1.size() || j>s2.size()) return false;
        
        //memoization
        if(dp[i][j]!=-1) return dp[i][j];
        
        //if both are same then check for both i.e. recursion
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j] = (f(i+1,j,k+1,s1,s2,s3,dp) || f(i,j+1,k+1,s1,s2,s3,dp));
        }
        else if(s1[i]==s3[k]){
            return dp[i][j] = f(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j] = f(i,j+1,k+1,s1,s2,s3,dp);
        }else{
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),len=s3.length();
        //initialization of dp
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,0,s1,s2,s3,dp);
    }
};