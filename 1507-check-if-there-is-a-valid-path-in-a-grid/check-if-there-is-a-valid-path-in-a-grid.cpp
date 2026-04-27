class Solution {
public:
    // mp[type] stores the two directions a street type connects.
    // 'l'=left, 'r'=right, 'u'=up, 'd'=down.
    vector<pair<char, char>> mp = {
        {' ', ' '}, // Padding for 0 index
        {'l', 'r'}, // 1: connects left and right
        {'u', 'd'}, // 2: connects upper and lower
        {'l', 'd'}, // 3: connects left and lower
        {'r', 'd'}, // 4: connects right and lower
        {'l', 'u'}, // 5: connects left and upper
        {'u', 'r'}  // 6: connects right and upper
    };

    // Helper to ensure we stay within grid boundaries
    bool is_valid(int i, int j, int m, int n){
        return i < m && i >= 0 && j < n && j >= 0;
    }

    // core traversal logic: follows the path starting from (i, j) in 'end' direction
    int func(int i, int j, int m, int n, char end, vector<vector<int>> &grid){
        while(true){
            // If we reach the bottom-right corner, we found a valid path
            if(i == m-1 && j == n-1) return 1; 

            // Move Left
            if(end == 'l'){
                if(is_valid(i, j-1, m, n)){
                    // Check if the next street has a right-side connection to receive us
                    if(mp[grid[i][j-1]].first == 'r' || mp[grid[i][j-1]].second == 'r'){
                        end = mp[grid[i][j-1]].first == 'r' ? mp[grid[i][j-1]].second : mp[grid[i][j-1]].first;
                        j--;
                    } else break;
                } else break;
            }
            // Move Right
            else if(end == 'r'){
                if(is_valid(i, j+1, m, n)){
                    // Check if the next street has a left-side connection
                    if(mp[grid[i][j+1]].first == 'l' || mp[grid[i][j+1]].second == 'l'){
                        end = mp[grid[i][j+1]].first == 'l' ? mp[grid[i][j+1]].second : mp[grid[i][j+1]].first;
                        j++;
                    } else break;
                } else break;
            }
            // Move Up
            else if(end == 'u'){
                if(is_valid(i-1, j, m, n)){
                    // Check if the next street has a down-side connection
                    if(mp[grid[i-1][j]].first == 'd' || mp[grid[i-1][j]].second == 'd'){
                        end = mp[grid[i-1][j]].first == 'd' ? mp[grid[i-1][j]].second : mp[grid[i-1][j]].first;
                        i--;
                    } else break;
                } else break;
            }
            // Move Down
            else if(end == 'd'){
                if(is_valid(i+1, j, m, n)){
                    // Check if the next street has an up-side connection
                    if(mp[grid[i+1][j]].first == 'u' || mp[grid[i+1][j]].second == 'u'){
                        end = mp[grid[i+1][j]].first == 'u' ? mp[grid[i+1][j]].second : mp[grid[i+1][j]].first;
                        i++;
                    } else break;
                } else break;
            }
            
            // If we loop back to the start, terminate to avoid infinite loop
            if(i == 0 && j == 0) return -1;
        }
        return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return true; // Edge case: single cell is valid

        int i = 0, j = 0;

        // Street 5 cannot be entered from (0,0) as it connects left/up (out of bounds)
        if(grid[i][j] == 5) return false; 

        // If starting street is type 4, we try both directions (first and second ports)
        if(grid[i][j] == 4){
            char end = mp[grid[i][j]].first;
            int res = func(i, j, m, n, end, grid);
            if(res == 1) return true;
            if(res == -1) return false;
        }

        // Try the second connection port of the starting cell
        char end = mp[grid[i][j]].second;
        int res = func(i, j, m, n, end, grid);
        if(res == 1) return true;
        if(res == -1) return false;

        // Verification for specific grid configurations
        return false;
    }
};