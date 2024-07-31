class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();
        vector<int> d(n/2);
        for(int i=0;i<n/2;i++){
            // // cout<<i<<endl;
            m[abs(nums[i] - nums[n-i-1])]++;
            d[i] = max({nums[i], nums[n-i-1], k - nums[i], k - nums[n-i-1]});
        }
        sort(d.begin(), d.end());
        // // cout<<s.size()<<endl;
        int ans = n/2;
        for (auto& it: m){
            // cout<<*it<<endl;
            int nn = n/2 - (lower_bound(d.begin(), d.end(), it.first) - d.begin());
            // cout<<it.first<<" "<<nn<<endl;

            ans = min(ans, nn + 2*(n/2 - nn) - it.second);
        }
        return ans;
    }
};