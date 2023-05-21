class Solution {
public:
    vector<int> row = {-1, 0, 1};
    
    // Depth-first search function to find the maximum number of moves
    int dfs(vector<vector<int>>& grid, int r, int c, int prev, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        
        // Check if the result for the current cell is already calculated
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        
        // Explore all possible moves from the current cell
        for (int i = 0; i < 3; i++) {
            int nr = r + row[i];
            int nc = c + 1;
            int val = 0;
            
            // Check if the move is valid and the value of the cell is strictly greater than the previous cell
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > prev) {
                val = 1 + dfs(grid, nr, nc, grid[nr][nc], dp);
                maxi = max(maxi, val);
            }
        }
        
        // Store the result for the current cell in the DP table
        return dp[r][c] = maxi;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        // Initialize the DP table with -1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        // Iterate over each cell in the first column and find the maximum number of moves
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(grid, i, 0, grid[i][0], dp));
        }
        
        return ans;
    }
};