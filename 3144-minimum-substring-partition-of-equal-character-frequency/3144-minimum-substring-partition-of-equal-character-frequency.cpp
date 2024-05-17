class Solution {
private:
    int solve(vector<int>& dp,string & s,int idx){
        if(idx==s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        unordered_map<char,int>mpp;
        int ans=1e9,var=1e9;
        for(int j=idx;j<s.length();j++){
            mpp[s[j]]++;
            int prevFreq = -1;
            bool check=true;
            for(auto it:mpp){
                if(prevFreq == -1){
                    prevFreq = it.second;
                }
                else if(prevFreq != it.second){
                    check = false;
                    break;
                }
            }
            if(check){
                var=1+solve(dp,s,j+1);
                ans=min(ans,var);
                //cout<<ans<<" ";
            }
        }
        return dp[idx]=ans;
    }
public:
    int minimumSubstringsInPartition(string s) {
        vector<int>dp(s.size(),-1);
        return solve(dp,s,0);
    }
};