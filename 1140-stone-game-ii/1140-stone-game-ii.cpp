class Solution {
  public:
    int dfs(int idx_start, int M, vector<int> &postfix, int n, vector<vector<int>> &cach) {
        if (idx_start >= n)
            return 0;

        int minnum = 1000001;
        if (cach[idx_start][M] >= 0) {
            return cach[idx_start][M];
        }
        for (int i = idx_start + 1; i <= idx_start + 2 * M && i <= n; i++) { 
            int tmp = dfs(i, std::max(i - idx_start, M), postfix, n, cach);
            if (minnum > tmp) {
                minnum = tmp;
            }
        }
        cach[idx_start][M] = postfix[idx_start] - minnum;
        return cach[idx_start][M];
    }
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();
        vector<int> postfix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            postfix[i] = postfix[i + 1] + piles[i];
        }
        vector<vector<int>> cach(n + 1, vector<int>(n + 1, -1));
        return dfs(0, 1, postfix, n, cach);
    }
};
