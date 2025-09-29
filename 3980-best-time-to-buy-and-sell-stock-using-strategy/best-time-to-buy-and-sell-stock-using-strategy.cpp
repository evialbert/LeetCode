class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& s, int k) {
        long long ans = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            ans +=1LL*prices[i]*s[i];
        }
        vector<long long>pre(n+1);
        pre[0] = 0;
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i]+prices[i];
        }
        vector<long long>pre2(n+1);
        pre2[0] = 0;
        for(int i=0;i<n;i++){
            pre2[i+1] = pre2[i]+prices[i]*s[i];
        }
        int x = k/2;
        for(int i=0;i<=n-k;i++){
            long long p = pre[i+k] - pre[i+x];
            p += pre2[i]-pre[0];
            p += pre2[n]-pre2[i+k];
            ans = max(ans,p);
        }
        return ans;
    }
};