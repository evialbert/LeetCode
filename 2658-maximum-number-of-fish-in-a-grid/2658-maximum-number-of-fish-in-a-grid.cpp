class Solution {
    int findMaxFishHelp(int i, int j, vector<vector<int>>& g) {
        if (i<0 || j<0 || i >= g.size() || j >= g[0].size() || !g[i][j]) return 0;
        int cnt = g[i][j];
        g[i][j] = 0;
        return cnt += findMaxFishHelp(i, j + 1, g) + findMaxFishHelp(i, j - 1, g) + findMaxFishHelp(i + 1, j, g) + findMaxFishHelp(i - 1, j, g);
    }
public:
    int findMaxFish(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, findMaxFishHelp(i, j, g));
            }
        }
        return maxi;
    }
};