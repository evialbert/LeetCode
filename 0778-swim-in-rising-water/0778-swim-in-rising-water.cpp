//Time complexity: O(N^2 log N) //Here, N = No. of row
//Space complexity: O(N^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,INT_MAX));
        vis[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        while(!pq.empty()){
            auto it= pq.top();
            int elevation=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ){
                    int temp;
                    if(elevation<grid[nrow][ncol]) 
                        temp=grid[nrow][ncol];
                    else
                        temp=elevation;
                    if(temp<vis[nrow][ncol]){
                        vis[nrow][ncol]=temp;
                    pq.push({temp,{nrow,ncol}});
                    }
                }
            }
        }return vis[n-1][n-1];
    }
};