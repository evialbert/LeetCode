class Solution {
public:
    int miceAndCheese(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = size(nums1), n2 = size(nums2);
        vector<pair<int, int>> v;
        for(int i = 0; i < n1; i++) {
            int d = nums2[i]-nums1[i];
            v.push_back({d, i});
        }
        sort(begin(v), end(v));
        unordered_set<int> ind;
        int ans = 0;
        for(int i = 0; i < size(v) and k; i++) {
            ans += nums1[v[i].second];
            k--;
            ind.insert(v[i].second);
        }
        for(int i = 0; i < n2; i++) {
            if(ind.count(i)) continue;
            ans += nums2[i];
        }
        return ans;
    }
};