class Solution {
public:
    unordered_map<string, int> dp;
    int solve(int i, int n, char strt, char end, vector<string> &w, int currSize) {
        if (i == n)
            return currSize;

        string temp = w[i];
        string key = to_string(i)+strt+end;
        if (dp.find(key) != dp.end())
            return dp[key];
        
        int a = currSize+solve(i+1,n,strt,temp[temp.size()-1],w,temp.size());
        if (end == temp[0])
            a--;
        int b = currSize+solve(i+1,n,temp[0],end,w,temp.size());
        if (strt==temp[temp.size()-1])
            b--;
        return dp[key] = min(a, b);
    }
    
    int minimizeConcatenatedLength(vector<string>& w) {
        int n = w.size();
        return solve(1,n,w[0][0],w[0][w[0].size()-1],w,w[0].size());
    }
};