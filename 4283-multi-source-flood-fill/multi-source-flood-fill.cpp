class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& s) {
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,0));
         vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<s.size();i++){
            int r=s[i][0];
            int c=s[i][1];
            int col=s[i][2];
            ans[r][c]=col;
            dist[r][c]=0;
            q.push({r,c});
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(dist[nrow][ncol]==-1){
                        dist[nrow][ncol]=dist[row][col]+1;
                        ans[nrow][ncol]=ans[row][col];
                        q.push({nrow,ncol});
                    }
else if(dist[nrow][ncol]==dist[row][col]+1)ans[nrow][ncol]=max(ans[nrow][ncol],ans[row][col]);
                }
            }
        }
        return ans;
    }
};