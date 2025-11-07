class Solution {
public:
    const int mod = 1e9+7;
    using ll = long long;
    void matmul(vector<vector<ll>> &a,vector<vector<ll>> b){
        int n = a.size(), m = a[0].size(), p = b[0].size();
        vector<vector<ll>> c(n,vector<ll>(p,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<p; j++){
                for(int k=0; k<m; k++){
                    c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
                }
            }
        }
        a = c;
    }
    vector<vector<ll>> pow_mod(vector<vector<ll>> &x, int y){
        int n = x.size();
        vector<vector<ll>> res(n,vector<ll>(n,0));
        for(int i=0; i<n; i++) res[i][i] = 1;
        while(y>0){
            if(y&1) matmul(res,x);
            y/=2; matmul(x,x);
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = (r-l+1);
        vector<vector<ll>> a(2*m,vector<ll>(2*m,0));
        vector<vector<ll>> dp(2*m,vector<ll>(1,1));

        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                a[i][j+m] = 1;
            }
            for(int j=i+1; j<m; j++){
                a[i+m][j] = 1;
            }
        }

        a = pow_mod(a,n-1);
        matmul(a,dp);
        long long ans = 0;
        for(int i=0; i<2*m; i++) ans += a[i][0], ans %= mod;
        return ans;
    }
};