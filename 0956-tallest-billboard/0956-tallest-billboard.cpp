class Solution {
public:
    int c(int s1,int i,vector<int>&r, vector<unordered_map<int, int>>& dp){
        if(i>=r.size()){
           if(s1)return INT_MIN;
           return 0;
        }
        if(dp[i].count(s1)){
            return dp[i][s1];
        }
        int ans = c(s1,i+1,r,dp);
        ans = max(ans,r[i] + c(s1-r[i],i+1,r,dp));
        ans = max(ans,c(s1+r[i],i+1,r,dp));
        return dp[i][s1]=ans; 
    }
    int tallestBillboard(vector<int>& r) {
        int n=r.size();
         vector<unordered_map<int, int>> dp(n+1);
         return c(0,0,r,dp);
    }
};