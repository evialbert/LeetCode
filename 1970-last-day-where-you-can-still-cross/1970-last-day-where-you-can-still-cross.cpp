class Solution {
public:
    bool isPathExist(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> &grid){
        vis[x][y]=true;
        if(x==grid.size()-1) return true;
        int delR[] = {-1,1,0,0};
        int delC[] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr = delR[k]+x;
            int nc = delC[k]+y;
            if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()
               &&!vis[nr][nc]&&grid[nr][nc]==0){
                if(isPathExist(nr,nc,vis,grid)==true) return true;
            }
        }
        return false;
    }
    bool isValid(int mid,int row,int col,vector<vector<int>>& cells){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<mid;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int i=0;i<col;i++){
            if(grid[0][i]==0 && !vis[0][i] && isPathExist(0,i,vis,grid)==true) return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1;
        int hi = cells.size();
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isValid(mid,row,col,cells)==true){
                ans = lo;
                lo = mid+1;
            }else{
                hi=mid-1;
            }
        }
        if(isValid(hi,row,col,cells)==true) return hi;
        else return ans;
    }
};