class Solution {
public:
    bool f(int i,int n,int a,string& s,vector<vector<int>>&dp){
        if(i==n){
            if(a==0)return true;
            return false;
        }
        if(dp[i][a]!=-1)return dp[i][a];
        int ans = false;
        if(s[i]=='('){
            ans |= f(i+1,n,a+1,s,dp);
        }else if(s[i]=='*'){
            ans |= f(i+1,n,a+1,s,dp);
            if(a) ans |= f(i+1,n,a-1,s,dp);
            ans |= f(i+1,n,a,s,dp);
        }else {
            if(a) ans |= f(i+1,n,a-1,s,dp);
        }
        return dp[i][a] = ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(101,-1));
        return f(0,s.size(),0,s,dp);
    }
};