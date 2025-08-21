class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>>vec(n,vector<int>(m));
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=m-1; j>=0 ;j--){
                if(mat[i][j]) cnt++;
                else cnt = 0;
                vec[i][j] = cnt;
            }
        }

        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x = INT_MAX;
                for(int k=i; k<n; k++){
                    x = min(x, vec[k][j]);
                    res += x;
                }
            }
        }

        return res;
    }
};