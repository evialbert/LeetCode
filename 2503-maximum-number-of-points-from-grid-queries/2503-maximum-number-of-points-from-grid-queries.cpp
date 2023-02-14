class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        priority_queue<vector<int>> q;
        q.push({-grid[0][0] , 0 , 0});
        vector<pair<int , int > > qu;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ;i < queries.size() ; i++ ){
            qu.push_back({queries[i] , i});
        }
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<int>fans(queries.size() , 0);
        sort(qu.begin() , qu.end());
        int ans = 0;
        vis[0][0] = 1 ;
        for(auto point : qu){
            auto it = point.first;
            int index = point.second;
            while(!q.empty() and -q.top()[0] < it){
                int curx = q.top()[1];
                int cury = q.top()[2];
                q.pop();
                ans++;
                
                for(int i = 0 ; i < 4 ; i++){
                    int nx = curx + x[i];
                    int ny = cury + y[i];
                    if(nx < 0 or nx >= n or ny >= m or ny < 0 or vis[nx][ny] == 1)continue;
                    vis[nx][ny] = 1;
                    q.push({-grid[nx][ny]  , nx , ny});
                }
            }
            
            fans[index] = ans;
            
        }
        return fans;
        
    }
};