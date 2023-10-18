class Solution {
public:
    int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>> row(n,vector<long long>(m)),col(n,vector<long long>(m));
        for(int i=0;i<n;i++){
            long long pro=1;
            for(int j=0;j<m;j++){
                pro=(pro*grid[i][j])%mod;
                row[i][j]=pro;
            }
            pro=1;
            for(int j=m-1;j>=0;j--){
                pro=(pro*grid[i][j])%mod;
                col[i][j]=pro;   
            }
        }
        vector<long long> pre(n),suff(n);
        for(int i=0;i<n;i++){
            if(i==0){
                pre[i]=(row[i][m-1])%mod;
            }else{
                pre[i]=(pre[i-1]*row[i][m-1])%mod;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suff[i]=(row[i][m-1])%mod;
            }else{
                suff[i]=(suff[i+1]*row[i][m-1])%mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long ans=1;
                if(j>0){
                    ans=(ans*row[i][j-1])%mod;
                }
                if(j<m-1){
                    ans=(ans*col[i][j+1])%mod;
                }
                if(i>0){
                    ans=(ans*pre[i-1])%mod;
                }
                if(i<n-1){
                    ans=(ans*suff[i+1])%mod;
                }
                grid[i][j]=ans;
            }
        }
        return grid;
    }
};