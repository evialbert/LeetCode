class Solution {
public:
    int mod=1000000007;
    int solve(string &s, int index, vector<bool> &vis, int last, vector<vector<int> > &dp){
        //if we reach the last index, there will be single element left we can do this in one way.
        if(index == s.size()){
            return 1;
        }
        
        if(dp[index][last] != -1) return dp[index][last];
        
        //when we need less than last one
        long long cnt = 0;
        if(s[index] == 'D'){
            for(int i=0; i<last; i++){
                if(vis[i]) continue;
                vis[i] = true;
                cnt+=(solve(s, index+1, vis, i, dp))%mod;
                vis[i] = false;
            }
        }
        
        //when we need greater than last one
        else{
            for(int i=last+1; i<=s.size(); i++){
                if(vis[i]) continue;
                vis[i] = true;
                cnt+=(solve(s, index+1, vis, i, dp))%mod;
                vis[i] = false;
            }
        }
        
        return dp[index][last] = cnt%mod;
    }
    int numPermsDISequence(string s) {
        vector<bool> vis(s.size()+1, false);
        vector<vector<int> > dp(s.size()+2, vector<int>(s.size()+2, -1));
        
        //start with any number at first position, then apply conditions in function
        long long cnt = 0;
        for(int i=0; i<=s.size(); i++){
            vis[i] = true;
            cnt+=(solve(s, 0, vis, i, dp))%mod;
            vis[i] = false;
        }
        
        return cnt%mod;
    }
};