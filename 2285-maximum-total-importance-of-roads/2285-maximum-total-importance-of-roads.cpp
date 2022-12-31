class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<long long> cnt(n, 0);
        for(auto &el: roads) {
            for(auto &x: el) {
                cnt[x]++;
            }
        }
        
        sort(cnt.begin(), cnt.end());
        long long q = n;
        for(int i=cnt.size()-1; i>=0; i--) {
            ans += (q * cnt[i]);
            q--;
        }
        return ans;
    }
};