class Solution {
    bool helper(string &s, set<string>& wordSet, vector<int>&dp, int pos){
        if(pos==s.size()) return true;
        if(dp[pos] != -1) return dp[pos];
        for(int i=pos+1; i<=s.size(); ++i)
            if(wordSet.count(s.substr(pos,i-pos)) and helper(s,wordSet,dp,i)) return dp[pos]=1;
        return dp[pos]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        for(auto a:wordDict) wordSet.insert(a);
        vector<int>dp(s.size(),-1);
        return helper(s, wordSet, dp, 0);
    }
};