class Solution {
public:
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int& n,int& m){
        if(i >= 0 && j >= 0 && j < m && i < n)
            return true;
        else
            return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int oranges = n*m;
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    oranges--;
                    q.push({i,j});
                    grid[i][j] = -1;
                }else if(grid[i][j] == 0){
                    oranges--;
                    grid[i][j] = -1;
                }
            }
        }if(oranges <= 0){
            return 0;
        }while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                auto temp = q.front();
                q.pop();
                int a = temp.first;
                int b = temp.second;
                for(auto& it:dir){
                    if(check(a+it[0],b+it[1],n,m) && grid[a+it[0]][b+it[1]] == 1){
                        grid[a+it[0]][b+it[1]] = -1;
                        oranges--;
                        q.push({a+it[0],b+it[1]});
                    }
                }
            }ans++;
        }return oranges <= 0 ? ans-1:-1;
    }
};