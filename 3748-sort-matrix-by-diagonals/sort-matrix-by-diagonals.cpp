class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            int n = grid.size()-i;
            vector<int> val(n);

            for(int j = 0; j < n; j++){
                val[j] = grid[i+j][j];
            }

            sort(val.begin(), val.end());

            for(int j = 0; j < grid.size()-i; j++){
                grid[i+j][j] = val[n-j-1];
            }
        }

        for(int i = 1; i < grid[0].size(); i++){
            int m = grid.size()-i;
            vector<int> val(m);
            for(int j = 0; j < m; j++){
                val[j] = grid[j][i+j];
            }

            sort(val.begin(), val.end());

            for(int j = 0; j < m; j++){
                grid[j][i+j] = val[j];
            }
        }

        return grid;
    }
};