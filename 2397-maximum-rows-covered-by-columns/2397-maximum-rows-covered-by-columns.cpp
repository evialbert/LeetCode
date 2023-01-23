class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        const int n = (int)mat.size(), m = (int)mat[0].size();
        int ans = 0;
        vector<bool> vis(m, false);
        function<void(int, int)> dfs = [&](int u, int cnt) -> void {
            if(cnt == cols) {
                int cur = 0;
                for(int i = 0; i < n; i++) {
                    bool flag = true;
                    for(int j = 0; j < m; j++) {
                        if(!vis[j] and mat[i][j]) flag = false;
                        if(!flag) break;
                    }
                    cur += flag;
                }
                ans = max(ans, cur);
            } else {
                for(int i = u + 1; i < m; i++) {
                    vis[i] = true;
                    dfs(i, cnt + 1);
                    vis[i] = false;
                }
            }
        };
        dfs(-1, 0);
        return ans;
    }
};