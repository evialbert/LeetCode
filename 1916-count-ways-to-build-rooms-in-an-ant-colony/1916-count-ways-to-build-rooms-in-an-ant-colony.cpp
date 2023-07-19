class Solution {
public:
    const long long mod = 1e9+7;
     int binpow(int a,int b){
        if(b==1) return a%mod;
        else {
            long long t = binpow(a,b/2);
            t = (t*t%mod)%mod; if(b%2) t = (t*a)%mod;
            return t;
        }
   }   
    int dfs(vector<vector<int>> &nums,vector<long long> &fac,vector<long long> &inv,vector<long long> &dp,vector<int> &sub,int in,int p){
        long long int re = 1, n = 0;
        for(int i = 0; i<nums[in].size();++i){
            n+=dfs(nums,fac,inv,dp,sub,nums[in][i],in);
        }
        sub[in] = n+1;
        for(int i = 0; i<nums[in].size();++i){
            int j = nums[in][i];
            int r = sub[j];
            re = (re*((fac[n]*inv[r])%mod*inv[n-r]%mod))%mod;
            re = (re*dp[j])%mod;
            n-=r;
        }
        dp[in] = re;
        return sub[in];
    }
    int waysToBuildRooms(vector<int>& arr) {
        int n = arr.size();
        
        vector<long long> fac(n+1,1), in(n+1,1);
        fac[0] = in[0] = 1;
        for(int i=1;i<=n;i++) fac[i] = (i*fac[i-1])%mod;
        in[n] = binpow(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) in[i] = (in[i+1]*(i+1))%mod;
        
        vector<vector<int>> nums(n);
        for(int i = 1; i<nums.size();++i) nums[arr[i]].push_back(i);
        
        vector<long long> dp(n+1,0);
        vector<int> sub(n,0);
        dfs(nums,fac,in,dp,sub,0,-1);
        
        return dp[0];
    }
};