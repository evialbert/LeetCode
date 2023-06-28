class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>, int>> q; // Stores the current point and cost to reach that point
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX)); 
        
        int arr1[4] = {0, 0, 1, -1}; // Row
        int arr2[4] = {1, -1, 0, 0}; // Column
        
        cost[0][0] = 0;
        q.push({{0,0}, 0});
        while(!q.empty()) {
            auto [x,y] = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int newCost = (grid[x][y] == i+1) ? c : c+1; // Cost to go to ith direction from current point
                int newX = x + arr1[i], newY = y + arr2[i]; 
                if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
                if(newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    q.push({{newX, newY}, newCost});
                }
            }
        }
        
        return cost[n-1][m-1];
    }
};