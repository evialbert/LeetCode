class Solution {
public:
    //using DFS Variation
    //dp and memoization
    //tc=o(n)
    //sc=o(n)
    int mod=1e9+7;
    int find(int i,string& s,int k,vector<int>& dp,int n){
        if(i==n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ways=0;
        long no=0;
        for(int j=i;j<n;j++){
            no=no*10+(s[j]-'0');
            if(no>k){
                break;
            }
            ways=(ways+find(j+1,s,k,dp,n))%mod;
        }
        return dp[i]=ways%mod;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n,-1);
        return find(0,s,k,dp,n);

    }
};