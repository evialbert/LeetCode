class Solution {
public:
    vector<int> dirx = {
        1,
        -1,
        0,
        0,
    }; // Direction vectors to check the neighbouring cells
    vector<int> diry = {0, 0, 1, -1}; // Y Direction Vector
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(
            row, vector<int>(
                     col, -1)); // Create a 2D vectore and initialize it with -1
                                // , so that it can be used to check whether the
                                // element is visited before or not
        queue<pair<int, int>> q; // Queue with co-ordinates to perform bfs
        for (int i = 0; i < row; i++) { // Initializing the bfs by pushing the
                                        // water cells with height 0
            // O(Row*Col)
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) { // Checking all neighbours
                if (dirx[i] + x >= 0 && dirx[i] + x < row && diry[i] + y >= 0 &&
                    diry[i] + y < col && ans[dirx[i] + x][diry[i] + y] == -1) {
                    ans[dirx[i] + x][diry[i] + y] =
                        ans[x][y] + 1; // Since max difference is 1
                    q.push({dirx[i] + x, diry[i] + y});
                }
            }
        }
        return ans;
        // Overall Time Complexity :O(Row*Col)+O(Row*Col*4)
        // Overall SPace Complexity :O(Row * Col)
    }
};