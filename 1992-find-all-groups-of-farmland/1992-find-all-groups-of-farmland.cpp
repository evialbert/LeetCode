class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios::sync_with_stdio(false);cin.tie(0);

        int m = land.size(), n = land[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0)    continue;

                int r2 = i;
                while (r2 < m && land[r2][j] == 1)
                    r2++;
                int c2 = j;
                while (c2 < n && land[i][c2] == 1)
                    c2++;

                r2 = r2 == 0 ? r2 : r2 - 1;
                c2 = c2 == 0 ? c2 : c2 - 1;
                result.push_back({i, j, r2, c2});

                for (int k = i; k <= r2; k++)
                    for (int l = j; l <= c2; l++)
                        land[k][l] = 0;
                
                j = c2;
            }
        }
        return result;
    }
};