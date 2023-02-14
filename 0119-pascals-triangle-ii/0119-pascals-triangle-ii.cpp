class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans[n];
    }
};