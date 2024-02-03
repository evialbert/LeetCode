class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
          int n = arr.size();
          int dp[n + 1];
          memset(dp, 0, sizeof(dp));
          for(int i= 1; i<=n; i++){
              int K = k;
              int cur_max = 0;
              int cur_ans = 0;
              for(int K = 1; K <= k && i - K >= 0; K++){
                  cur_max = max(cur_max, arr[i-K]);
                  cur_ans = max(cur_ans, dp[i-K] + K * cur_max);
              }
              dp[i] = cur_ans;
          }
           return dp[n];
    }
};