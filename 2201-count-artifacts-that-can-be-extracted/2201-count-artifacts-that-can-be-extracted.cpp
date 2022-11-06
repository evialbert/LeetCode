class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int mat[n+1][n+1];
        memset(mat, 0, (n+1)*(n+1)*sizeof(int));
        for(int i=0; i<dig.size(); i++)
            mat[dig[i][0]+1][dig[i][1]+1] = 1;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        int ans = 0, i1,j1,i2,j2;
        for(int i=0; i<artifacts.size(); i++) {
            i1 = artifacts[i][0]+1; j1 = artifacts[i][1]+1;
            i2 = artifacts[i][2]+1; j2 = artifacts[i][3]+1;
            if(mat[i2][j2]-mat[i2][j1-1]-mat[i1-1][j2]+mat[i1-1][j1-1] ==
               (i2-i1+1)*(j2-j1+1)) ans++;
        }
        return ans;
    }
};