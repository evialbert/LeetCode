class Solution {
public:
int minimumTime(vector<vector<int>>& grid) {
    // Check if the starting points are blocked
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
    
    int n = grid.size(), m = grid[0].size();
    int dirs[]={1,0,-1,0,1};
    int visited[n][m];
    memset(visited,0,sizeof visited);
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    
    pq.push({grid[0][0], 0, 0}); // Start at top-left corner
    while (!pq.empty()) {
        // Get the current time, row, and column
        int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
        pq.pop();
        
        if (row == n - 1 && col == m - 1) return time;
        
        if (visited[row][col]) continue;
        visited[row][col] = true;
        for (int i=0;i<4;i++) {
            int r = row + dirs[i], c = col + dirs[i+1];
            if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c]) continue;
            int wait = (grid[r][c] - time) % 2 == 0?1:0; // we would have to wait 1 more extra unit of time if the difference was already odd. 
            pq.push({max(grid[r][c] + wait, time + 1), r, c});
        }
    }
    return -1; 
}
};