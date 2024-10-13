class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& a) {
        int n = source.size();
        int m = pattern.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        set<int> st(a.begin(),a.end());
        function<int(int,int)> dfs = [&](int i,int j)->int{
            if(i==n){
                return j==m ? 0 : -1e5;
            }
            if(dp[i][j]!=-1)return dp[i][j];
            dp[i][j] = dfs(i+1,j);
            if(st.find(i)!=st.end()){
                dp[i][j] = max(dp[i][j],1+dfs(i+1,j));
            }
            if(j<m && source[i]==pattern[j]){
                dp[i][j] = max(dp[i][j],dfs(i+1,j+1));
            }
            return dp[i][j];
        };
        return dfs(0,0);
    }
};