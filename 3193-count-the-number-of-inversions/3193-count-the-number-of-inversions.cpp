class Solution {
public:
   int mod = 1e9 + 7;
    int ans(int ind,int cnt,vector<vector<long long>> &dp,map<int,int> &mp)
    {
        if(mp[ind] && mp[ind]!=cnt){
            // cout<<ind<<endl;
            return 0;
        }
        if(ind==0){
            // cout<<"vimal"<<endl;
            return cnt==1;
        }
        
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }
        int sumi=0;
        for(int i=0;i<=min(cnt,ind);i++){
          sumi= (sumi + ans(ind-1,cnt-i,dp,mp))%mod;
        }
        return dp[ind][cnt]=sumi;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int m=requirements.size();
        vector<vector<long long>> dp(n+1,vector<long long> (402,-1));
        map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[requirements[i][0]] = requirements[i][1] + 1;
        }
        return ans(n-1,mp[n-1],dp,mp);
    }
};