class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                else if(i==0) mat[i][j] += mat[i][j-1];
                else if(j==0) mat[i][j] += mat[i-1][j];
                else mat[i][j] += (mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]);
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mir = max(i-k,0);
                int mic = max(j-k,0);
                int mar = min(i+k,n-1);
                int mac = min(j+k,m-1);
                
                if(mir==0 && mic==0) ans[i][j] = mat[mar][mac];
                else if(mir==0) ans[i][j] = mat[mar][mac] - mat[mar][mic-1];
                else if(mic==0) ans[i][j] = mat[mar][mac] - mat[mir-1][mac];
                else ans[i][j] = mat[mar][mac] - mat[mar][mic-1] - mat[mir-1][mac] + mat[mir-1][mic-1];
            }
        }
        
        return ans;
    }
};