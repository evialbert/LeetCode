class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
       vector<int>dp(n+1,1e9);
       dp[0] = 0;
       dp[1] = costs[0] + 1;
       for(int i = 2; i<=n; i++){
          if(i-1>=0)dp[i] = min({dp[i],dp[i-1]+costs[i-1]+(i-(i-1))*(i-(i-1))});
          if(i-2>=0)dp[i] = min({dp[i],dp[i-2]+costs[i-1]+(i-(i-2))*(i-(i-2))});
          if(i-3>=0)dp[i] = min({dp[i],dp[i-3]+costs[i-1]+(i-(i-3))*(i-(i-3))});

       }
       return dp[n];
    }
};


