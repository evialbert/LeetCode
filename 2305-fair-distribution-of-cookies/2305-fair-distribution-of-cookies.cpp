class Solution {
    int n;
    int ans = INT_MAX;
    int sum[8] = {};
public:
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        sort(cookies.begin(), cookies.end(), greater<int>());
        dfs(cookies, k, 0, 0);
        return ans;
    }
    
    void dfs(vector<int>& cookies, int k, int i, int maxsum) {
        if (maxsum >= ans) return;
        
        if (i == n) {
            ans = maxsum;
            return;
        }
        
        for (int j = 0; j < k; j++) {
            sum[j] += cookies[i];
            dfs(cookies, k, i+1, max(maxsum, sum[j]));
            sum[j] -= cookies[i];
        }
    }
};