class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end, ans;
        for(vector<int> &f : flowers)
        {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(int &num : persons)
        {
            auto its = upper_bound(start.begin(), start.end(), num);
            auto ite = lower_bound(end.begin(), end.end(), num);
            int x = its-start.begin();
            int y = ite-end.begin();
            ans.push_back(x-y);
        }
        return ans;
    }
};