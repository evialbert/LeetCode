class NeighborSum {
    vector<vector<int>>a;
    unordered_map<int,pair<int,int>>m;
public:
    NeighborSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            vector<int>temp;
            for(int j=0; j<grid[i].size(); j++){
                temp.push_back(grid[i][j]);
                m[grid[i][j]] = {i, j};
            }
            a.push_back(temp);
        }
    }
    
    int adjacentSum(int value) {
        int res = 0;
        int i = m[value].first, j = m[value].second;
        if(i>0) res+=a[i-1][j];
        if(i<a.size()-1) res += a[i+1][j];
        if(j>0) res += a[i][j-1];
        if(j<a[i].size()-1) res+= a[i][j+1];
        return res;
    }
    
    int diagonalSum(int value) {
        int res = 0;
        int i = m[value].first, j = m[value].second;
        if(i>0 && j>0) res+=a[i-1][j-1];
        if(i<a.size()-1 && j<a[i].size()-1) res += a[i+1][j+1];
        if(i<a.size()-1 && j>0) res += a[i+1][j-1];
        if(i>0 && j<a[i].size()-1) res+= a[i-1][j+1];
        return res;
    }
};


/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */