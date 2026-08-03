class Solution {
public:
    pair<int,int> recurse(vector<pair<int,int>> &dp, vector<int> &a, int curr, int n) {
        if (curr >= n) return {0, 0};
        
        pair<int,int> best = {INT_MIN, INT_MAX};
        int sum = 0;
        
        for(int i = 0; i <= 2; ++i) {
            if (curr + i >= n) break;
            sum += a[curr + i];
            
            pair<int,int> cur = (dp[curr + i + 1] == pair<int,int>{-1, -1}) 
                                ? recurse(dp, a, curr + i + 1, n) 
                                : dp[curr + i + 1];
                                
            if (sum + cur.second > best.first) {
                best = {sum + cur.second, cur.first};
            }
        }
        return dp[curr] = best;
    }
    
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>> dp(n + 3, {-1, -1});
        
        pair<int,int> ans = recurse(dp, a, 0, n);
        
        if (ans.first > ans.second) return "Alice";
        else if (ans.first < ans.second) return "Bob";
        
        return "Tie";
    }
};