class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        vector<vector<int>>temp(n,vector<int>(m));
        for(int i=0;i<n;++i){
            if(i%2==0){
                for(int j=0;j<m;++j){
                    temp[i][j]=mat[i][(j+m-k)%m];
                }
            }
            else{
                for(int j=0;j<m;++j){
                    temp[i][j]=mat[i][(j+k)%m];
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]!=temp[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};