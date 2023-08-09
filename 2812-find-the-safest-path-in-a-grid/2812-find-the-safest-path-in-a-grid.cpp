class Solution {
public:
    vector<vector<int>> manh;
    vector<vector<int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        queue<vector<int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    manh[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            for(auto dir:direc){
                int nx = x+dir[0];
                int ny = y+dir[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && manh[nx][ny]==-1){
                    manh[nx][ny] = manh[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int func(vector<vector<int>>& grid){
        int n = grid.size();
        priority_queue<vector<int>> pq;
        vector<vector<int>> safe(n, vector<int>(n, INT_MAX));
        pq.push({manh[0][0], 0, 0});
        safe[0][0] = manh[0][0];
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int safety = pq.top()[0];
            pq.pop();
            if(x == n-1 && y == n-1){
                return safety;
            }
            for(auto dir:direc){
                int nx = x+dir[0];
                int ny = y+dir[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && safe[nx][ny]==INT_MAX){
                    safe[nx][ny] = min(safety, manh[nx][ny]);
                    pq.push({safe[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<int> temp(grid.size(), -1);
        for(int i = 0; i<grid.size(); i++){
            manh.push_back(temp);
        }
        bfs(grid);
        return func(grid);
    }
};