class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> prev(grid[0].size(), vector<int> (2, 0));
        int count = 0, n = grid.size(), m = grid[0].size(), xCount, yCount;
        for(int i = 0; i < n; i++) {
            xCount = 0, yCount = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') xCount ++;
                if(grid[i][j] == 'Y') yCount ++;
                prev[j][0] += xCount;
                prev[j][1] += yCount;
                if(prev[j][0] > 0 && prev[j][0] == prev[j][1]) count ++;
            }
        }
        return count;

    }
};