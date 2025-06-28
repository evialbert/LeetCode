class Solution {
    bool isConsec(char a, char b){
        int dis = abs(a-b);
        return dis == 1 || dis == 25;
    }
    vector<vector<bool>> allRemove;
    void constructRemove(const string& s){ 
        // For s[start, end), O(n^3)
        int n = s.size();
        for(int len = 1; len <= n; ++len){
            for(int start = 0, end = len; end <= n; ++start, ++end){
                allRemove[start][end] = false;
                if(len % 2 == 0) {
                    if(isConsec(s[start], s[end-1]) && allRemove[start+1][end-1]){
                        allRemove[start][end] = true;
                        continue;
                    }
                    for(int mid = start + 2; mid < end; mid += 2){
                        if(allRemove[start][mid] && allRemove[mid][end]){
                            allRemove[start][end] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
public:
    string lexicographicallySmallestString(string s) {
        // Approach 3: 2 * DP O(n^3)
        int n = s.size();
        // allRemove[i][j] = true when s[i~j) can all remove
        allRemove.resize(n+1, vector<bool>(n+1, true));
        constructRemove(s);
        // dp[i] mean the lexicographically smallest string of s[i~n) 
        vector<string> dp(n+1, "");
        for(int start=n-1; start>=0; --start){
            dp[start] = s[start] + dp[start+1];
            for(int mid = start+1; mid < n; mid += 2){
                if(allRemove[start+1][mid] && isConsec(s[start], s[mid])){
                    if(dp[mid+1] < dp[start])
                        dp[start] = dp[mid+1];
                }
            }
        }
        return dp[0];
    }
};