class Solution {
public:
    long long int dp[20001][26];
    int mod=1000000007;
    long long int helper(int n, char c){
        if(n==0){
            return 1;
        }
        if(dp[n][c-'a']!=-1){
            return dp[n][c-'a'];
        }
        long long int res=0;
        if(c=='a'){
            res+=helper(n-1,'e')%mod;
        }
        if(c=='e'){
            res+=helper(n-1,'a')%mod;
            res+=helper(n-1,'i')%mod;
        }
        if(c=='i'){
            res+=helper(n-1,'a')%mod;
            res+=helper(n-1,'e')%mod;
            res+=helper(n-1,'u')%mod;
            res+=helper(n-1,'o')%mod;
        }
        if(c=='o'){
            res+=helper(n-1,'i')%mod;
            res+=helper(n-1,'u')%mod;
        }
        if(c=='u'){
            res+=helper(n-1,'a')%mod;
        }
        return dp[n][c-'a']=res%mod;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        long long int res=helper(n-1,'a')+helper(n-1,'e')+helper(n-1,'i')+helper(n-1,'o')+helper(n-1,'u');
        return res%mod;
    }
};