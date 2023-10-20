class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> m1;
        int ans = 0;
        for(auto x : nums3)
        {
            for(auto y : nums4)
            {
                m1[x+y]++;
            }
        }
        
        for(auto x : nums1)
        {
            for(auto y : nums2)
            {
                ans += m1[-1*(x+y)];
            }
        }
        return ans;
    }
};