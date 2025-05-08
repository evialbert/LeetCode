class Solution {
public:
    vector<vector<int>>dp;
    int n, kk;

    bool tdp(int msk, int rem, vector<int>&A){
        if(msk == ((1<<n) - 1))return (rem==0);
        if(dp[msk][rem]!=-1)return dp[msk][rem];
        bool ans = 0;
        for(int i=0;i<n;i++){
            if(!(msk & (1<<i))){
                int num = A[i], mul=1;
                while(num){num/=10;mul*=10;}
                int nr = (rem*mul + A[i])%kk;
                ans |= tdp(msk|(1<<i), nr, A);
            }
        }
        return dp[msk][rem]=ans;
    }

    void getarray(int in, int msk, int rem, vector<int>&ans, vector<int>& A){
        if(in==n)return;
        int nmsk, nrem;
        for(int i=0;i<n;i++){
            if(!(msk & (1<<i))){
                int num = A[i], mul=1;
                while(num){num/=10;mul*=10;}
                int nr = (rem*mul + A[i])%kk;
                if(tdp(msk|(1<<i), nr, A)==1 && ans[in]>A[i]){
                    nmsk = msk|(1<<i);
                    nrem = nr;
                    ans[in]=A[i];
                }
            }
        }
        getarray(in+1, nmsk, nrem, ans, A);
        return;
    }

    vector<int> concatenatedDivisibility(vector<int>& A, int k) {
        n=A.size();kk=k;
        dp.resize(1<<n, vector<int>(k, -1));
        bool ispos = tdp(0, 0, A);
        if(!ispos)return {};
        vector<int>ans(n, INT_MAX);
        getarray(0, 0, 0, ans, A);
        return ans;
    }
};