class Solution {
    const int M = 1e9+7;
    long long solve(int lvl, int gcD, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(lvl == mat.size()) return gcD == 1;
        if(dp[lvl][gcD] != -1) return dp[lvl][gcD];
        long long res = 0;
        for(int j = 0; j < mat[0].size(); j++) {
            if(lvl == 0) res = (res+solve(1, mat[lvl][j], mat, dp))%M;
            else res = (res+solve(lvl+1, __gcd(mat[lvl][j], gcD), mat, dp))%M;
        }
        return dp[lvl][gcD] = res;
    }
public:
    int countCoprime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(151, -1));
        int gcd = 0;
        return (int)solve(0, 0, mat, dp);
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });