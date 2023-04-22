class Solution {
public:
    bool solve(vector<vector<int>>& grid, int r, int c, int n, int score) {
        if (r<0 || c<0 || r>=n || c>=n || grid[r][c] != score) return false;
        if (((n*n == score+1)) && (grid[r][c] == score)) return true;
        grid[r][c] = -1;
        
        return (solve(grid, r+2, c+1, n, score+1) || 
                solve(grid, r+2, c-1, n, score+1) ||
                solve(grid, r-2, c+1, n, score+1) ||
                solve(grid, r-2, c-1, n, score+1) ||
                solve(grid, r+1, c+2, n, score+1) ||
                solve(grid, r-1, c+2, n, score+1) ||
                solve(grid, r+1, c-2, n, score+1) ||
                solve(grid, r-1, c-2, n, score+1));
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, 0, 0, n, 0);
    }
};