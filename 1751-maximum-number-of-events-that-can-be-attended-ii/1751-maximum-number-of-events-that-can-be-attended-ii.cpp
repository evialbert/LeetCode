class Solution {
public:
    int maxValue(vector<vector<int>>& a, int k) {
        //dp[i] = dp[i + 1], dp[ind +1] + a[i]
        sort(a.begin(), a.end());
        int n = a.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        vector<int> st;
        for(auto &e: a) st.push_back(e[0]);
        for(int i = n - 1; i>= 0; --i){
            for(int j = 0; j <=k; ++j){
                if(i == n || j == 0) dp[i][j] = 0;
                else{
                    int nt = dp[i + 1][j];
                    int t = -1e9 - 10;
                    int ind = upper_bound(st.begin() + i + 1, st.end(), a[i][1]) - st.begin();
                    t = a[i][2] + dp[ind][j - 1];
                    dp[i][j] = max(t, nt);
                }
            }
        }
        return dp[0][k];
    }
};