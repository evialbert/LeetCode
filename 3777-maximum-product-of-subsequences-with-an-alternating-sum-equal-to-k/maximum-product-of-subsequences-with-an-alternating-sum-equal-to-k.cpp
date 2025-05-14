class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>dp;

    int tdp(int in, int isodd, int as, int prod, vector<int>& A, int k, int lim){
        if(in==A.size()){
            return ((prod<=lim) && (as==k) && isodd)?prod:INT_MIN;
        }
        if(dp.count(in) && dp[in].count(isodd) && dp[in][isodd].count(as) && dp[in][isodd][as].count(prod))return dp[in][isodd][as][prod];

        int ans=tdp(in+1, isodd, as, prod, A, k, lim);
        if(isodd==0)ans=max(ans, tdp(in+1, 2, as+A[in], A[in], A, k, lim));
        else if(isodd==1)ans=max(ans, tdp(in+1, 2, as+A[in], min(A[in]*prod, lim+1), A, k, lim));
        else ans=max(ans, tdp(in+1, 1, as-A[in], min(A[in]*prod, lim+1), A, k, lim));
        return dp[in][isodd][as][prod]=ans;
    }

    int maxProduct(vector<int>& A, int k, int limit) {
        int ts=0;
        for(auto&a:A)ts+=a;
        if(ts<k || -ts>k)return -1;
        int ans = tdp(0, 0, 0, 0, A, k, limit);
        return (ans==INT_MIN)?-1:ans;
    }
};