class Solution {
public:
    unordered_map<string,int> mp;
    int n;
    int solve(string &s,int idx,vector<int> &dp){
        if(idx>=n){
            return 0;
        }
        
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        //ignoring current index(not picking)
        string temp="";
        int ans=solve(s,idx+1,dp);

        //considering all possible strings(multiple picks)
        for(int i=idx ; i<n ; i++){
            temp+=s[i];
            if(mp[temp]){
                ans=max(ans,(int)temp.size()+(int)solve(s,i+1,dp));
            }
        }
        
        return dp[idx]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.size();
        vector<int> dp(n+1,-1);
        for(auto e : dictionary){
            mp[e]=1;
        }
        return n-solve(s,0,dp);
    }
};