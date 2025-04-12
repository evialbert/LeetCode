class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);cout.tie(NULL);
        int ans = a[0];
        for (int i = 1;i < a.size();++i) ans = ans + max(0, a[i]-a[i-1]);
        return ans;
    }
};