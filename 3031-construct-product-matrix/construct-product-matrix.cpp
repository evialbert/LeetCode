class Solution {
public:
    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD=12345;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        uint64_t prefix =1, suffix =1;

        for(int i=0;i<n;i++){ // prefix 
            for(int j=0;j<m;j++){
                ans[i][j]= prefix;
                prefix *= grid[i][j];
                prefix  %= MOD;
            }
        }
        for(int i=n-1; i>=0; i--){ // building suffix
            for(int j=m-1; j>=0; j--){
                ans[i][j] *= suffix;
                ans[i][j] %= MOD;
                suffix  *= grid[i][j];
                suffix  %= MOD;
            }
        }
        return ans;
    }
};