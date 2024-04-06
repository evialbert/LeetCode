class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        map<long, long> sum, diff;
        for(auto i:points) {
            sum[i[0] + i[1]]++;
            diff[i[0] - i[1]]++;
        }
        long long ans = INT_MAX;
        for(auto p:points) {
            long long a = p[0] + p[1];
            long long b = p[0] - p[1];
            if(--sum[a] == 0) sum.erase(a);
            if(--diff[b] == 0) diff.erase(b);
            if (!sum.empty() && !diff.empty()) {
                auto it1 = sum.rbegin();
                auto it2 = sum.begin();
                auto it3 = diff.rbegin();
                auto it4 = diff.begin();
                long long x = it1->first - it2->first;
                long long y = it3->first - it4->first;
                ans = min(ans, max(x, y));
            }
            sum[a]++;diff[b]++;
        }
        return ans;
    }
};