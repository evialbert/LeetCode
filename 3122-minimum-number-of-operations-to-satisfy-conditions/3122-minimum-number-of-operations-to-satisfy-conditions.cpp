class Solution {
public:
    int n, m;
    int mem[int(1e3+1)][11];
    int freq[int(1e3+1)][10];
    int rec(int j, int prev, vector<vector<int>> &grid) {
        if(j==m || j<0) return 0;
        if(mem[j][prev+1] != -1) return mem[j][prev+1];
        int tmp = INT_MAX;
        for(int k = 0; k<10; k++) {
            if(prev == k) continue;
            int res = rec(j+1, k, grid);
            tmp = min(tmp,  n-freq[j][k]+res);
        }
        return mem[j][prev+1] = tmp;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(mem, -1, sizeof(mem));
        for(int j = 0; j<m; j++) {
            for(int i = 0; i<n; i++) freq[j][grid[i][j]]++;
        }
        return rec(0, -1, grid);
    }
};