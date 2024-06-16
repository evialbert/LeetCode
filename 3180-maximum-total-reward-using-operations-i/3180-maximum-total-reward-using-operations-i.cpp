class Solution {
public: 
    int kp(int i,vector<vector<int>> &dp,int sum,vector<int> &rv) {
        if(i==rv.size()) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=0;
        if(rv[i]>sum){
            ans=max(rv[i]+kp(i+1,dp,sum+rv[i],rv),kp(i+1,dp,sum,rv));
        } else {
            ans=kp(i+1,dp,sum,rv);
        }
        return dp[i][sum]=ans;
    }
    int maxTotalReward(vector<int>& rv) {
    sort(rv.begin(), rv.end()); 
    vector<vector<int>> dp(rv.size()+1,vector<int>(rv[rv.size()-1]*2,-1));
    return kp(0,dp,0,rv);
    }
};