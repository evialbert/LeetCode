class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n-2, vector<int>(n-2,-1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int p=min(i, n-3); p>=max(i-2, 0); p--)
                    for(int q=min(j, n-3); q>=max(j-2, 0); q--)
                        v[p][q] = max(v[p][q], grid[i][j]);
            }
        }
        return v;
    }
};