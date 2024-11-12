class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        sort(items.begin(), items.end());
        vector<int> ans(m);

        vector<int> mostBeauty(n);
        mostBeauty[0] = items[0][1];
        for (int i = 1; i < n; i++) mostBeauty[i] = max(mostBeauty[i-1], items[i][1]);

        for (int i = 0; i < m; i++) {
            int l = 0, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (items[mid][0] > queries[i]) r = mid;
                else l = mid + 1;
            }
            
            if (l == 0) ans[i] = 0;
            else ans[i] = mostBeauty[l - 1];
        }

        return ans;
    }
};