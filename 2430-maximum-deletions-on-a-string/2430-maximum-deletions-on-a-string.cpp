class Solution {
public:
    int solve(string_view &s, int i, int j, vector<vector<int>> &dp) {
        if(i == s.size())   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int res = INT_MIN;
        for(int k = j; k < s.size(); k++) {
            string_view a = s.substr(i, k-i);
            string_view b = s.substr(k, k-i);
            
            if(a == b) {
                int x = solve(s, k, k+1, dp);
                if(x != INT_MIN)    res = max(res, x+1);
            }
        }
        
        int ans = (res == INT_MIN) ? 1 : res;
        return dp[i][j] = ans;
    }
    
    int deleteString(string s) {
        if(s.size() == 1)   return 1;
        string_view sv({s.c_str(), s.size()});
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, -1));
        return solve(sv, 0, 1, dp);
    }
};