class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> pos;
        unordered_map<int, unordered_map<int, int>> cnt;
        vector<vector<int> > dp(k, vector<int>(1024, INT_MAX));
        
        for(int i = 0; i < n; i++) {
            cnt[i%k][nums[i]]++;
            pos[i%k].insert(nums[i]);
        }
        
        int bestuptoi = 0;
        for(int i = 0; i < k; i++) {
            int bestati = INT_MAX;
            int totalPos = ceil((n-i)*1.0/k);
            
            for(int j = 0; j < 1024; j++) {
                if(i == 0) {
                    dp[i][j] = min(dp[i][j], totalPos-cnt[i][j]);
                } else {
                    for(auto x : pos[i]) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j^x] + totalPos-cnt[i][x]);
                    }
                }
                dp[i][j] = min(dp[i][j], bestuptoi + totalPos);
                bestati = min(dp[i][j], bestati);
            }
            
            bestuptoi = bestati;
        }
        return dp[k-1][0];
    }
};