class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<string> p5 = {"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"};
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < s.size(); i++){
            for(string x : p5){
                if(x.size() > i+1)break;
                if(dp[i+1-x.size()] != INT_MAX && x == s.substr(i+1-x.size(), x.size())){
                    dp[i+1] = min(dp[i+1], dp[i+1-x.size()]+1);
                }
            }
        }
        if(dp[n] == INT_MAX)return -1;
        return dp[n];
    }
};