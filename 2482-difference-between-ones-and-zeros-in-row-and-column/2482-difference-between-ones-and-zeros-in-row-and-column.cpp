class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(); //rows
        int n=grid[0].size(); //columns
        vector<int> r(m,0);
        vector<int> c(n,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    r[i]++; c[j]++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j]=2*(r[i]+c[j])-m-n;
            }
        }
        return grid;
        
    }
};