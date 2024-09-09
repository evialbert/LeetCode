class Solution {
public:
    
    int dr[8]={2,2,1,1,-1,-1,-2,-2},dc[8]={1,-1,2,-2,2,-2,1,-1};
    
    int foo(int curpos, int bitmask, vector<vector<vector<int>>>& cost, vector<vector<int>>& positions, vector<vector<int>>& dp){
        int n=positions.size();
        if(bitmask==(1<<(n))-1) return 0;
        if(dp[curpos][bitmask]!=-1) return dp[curpos][bitmask];
        int setbits=__builtin_popcount(bitmask);
        if(setbits&1){
            int ans=INT_MAX;
            for(int i=0;i<n;++i){
                if((bitmask>>i)&1) continue;
                ans=min(ans,foo(i,bitmask|(1<<i),cost,positions,dp)+cost[curpos][positions[i][0]][positions[i][1]]);
            }
            return dp[curpos][bitmask]=ans;
        }
        else{
            int ans=0;
            for(int i=0;i<n;++i){
                if((bitmask>>i)&1) continue;
                ans=max(ans,foo(i,bitmask|(1<<i),cost,positions,dp)+cost[curpos][positions[i][0]][positions[i][1]]);
            }
            return dp[curpos][bitmask]=ans;
        }
        
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n=positions.size();

        //store costs from each position to all other positions
        vector<vector<vector<int>>> cost(n, vector<vector<int>>(50, vector<int>(50)));

        //BFS from each position to fill cost matrix
        for(int i=0;i<n;++i){
            int x=positions[i][0],y=positions[i][1];
            vector<vector<int>> vis(50, vector<int>(50));
            vis[x][y]=1;
            queue<pair<int,int>> q;
            q.push({x,y});
            int dis=0;
            while(!q.empty()){
                dis++;
                int sz=q.size();
                while(sz--){
                    int nx=q.front().first,ny=q.front().second;
                    q.pop();
                    for(int k=0;k<8;++k){
                        int r=nx+dr[k],c=ny+dc[k];
                        if(r>=0 && r<50 && c>=0 && c<50 && vis[r][c]==0){
                            cost[i][r][c]=dis;
                            vis[r][c]=1;
                            q.push({r,c});
                        }
                    }
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(1<<n,-1));
        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,foo(i,1<<i,cost,positions,dp)+cost[i][kx][ky]);
        }
        return ans;
    }
};