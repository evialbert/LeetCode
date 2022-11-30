class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void paci(vector<vector<int>>& h,vector<vector<pair<bool,bool>>>& ocean,int n,int m,int i,int j){
        ocean[i][j].first=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !ocean[nx][ny].first && h[nx][ny]>=h[i][j]){
                paci(h,ocean,n,m,nx,ny);
            }
        }
    }
    void atla(vector<vector<int>>& h,vector<vector<pair<bool,bool>>>& ocean,int n,int m,int i,int j){
        ocean[i][j].second=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !ocean[nx][ny].second && h[nx][ny]>=h[i][j]){
                atla(h,ocean,n,m,nx,ny);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();int m=h[0].size();
        //ocean.first for pacific 
        //ocean.second for atlantic
        vector<vector<pair<bool,bool>>> ocean(n,vector<pair<bool,bool>>(m,{false,false}));
        for(int i=0;i<n;i++){
            paci(h,ocean,n,m,i,0);
            atla(h,ocean,n,m,i,m-1);
        }
        for(int i=0;i<m;i++){
            paci(h,ocean,n,m,0,i);
            atla(h,ocean,n,m,n-1,i);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ocean[i][j].first && ocean[i][j].second)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};