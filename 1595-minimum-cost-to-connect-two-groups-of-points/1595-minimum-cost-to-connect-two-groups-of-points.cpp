class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& C) {
         int m = C.size(), n = C[0].size(), dp[13][4097]{}, min2[13] = {[0 ... 12] = INT_MAX};
         for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) min2[j] = min(min2[j], C[i][j]);
         function<int(int, int)> dfs = [&] (int i, int mask) {
             if(dp[i][mask]) return dp[i][mask];
             int res = (i >= m ? 0 : INT_MAX);
             for(int j = 0; j < n; j++) {
                 if(i >= m) res += min2[j]*(!(mask&(1 << j)));
                 else res = min(res, C[i][j]+ dfs(i+1, mask | (1 << j)));
             }
             return dp[i][mask] = res;
         };
         return dfs(0, 0);
    }
};