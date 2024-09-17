class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int bfs(vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();
        deque<pair<int,int>>dq;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dq.push_back({0,0});
        dis[0][0]=g[0][0];
        while(!dq.empty()){
            auto cur = dq.front();
            auto x=cur.first,y=cur.second;
            dq.pop_front();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(dis[nx][ny]>dis[x][y]+g[nx][ny]){
                        dis[nx][ny]=dis[x][y]+g[nx][ny];
                        if(!g[nx][ny]){
                            dq.push_front({nx,ny});
                        }
                        else{
                            dq.push_back({nx,ny});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
    bool findSafeWalk(vector<vector<int>>& g, int h) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        return (h-bfs(g))>=1;
    }
};