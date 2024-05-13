class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for(int col = 0; col < grid[0].size(); col++) {
            for(int row = 1; row < grid.size(); row++) {
                if(grid[row][col] != grid[0][col]) return false;
            }
        }
        for(int col = 1; col < grid[0].size(); col++) {
            if(grid[0][col] == grid[0][col - 1]) return false;
        }
        return true;
    }
};