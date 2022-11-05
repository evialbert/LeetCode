class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
			if(nums[i] == 0) {
				v.push_back({mapping[0], i});
				continue;
			}
            int m = nums[i];
            int val = 0;
            int j = 1;
            while(m > 0) {
                int t = m % 10;
                val = mapping[t] * j + val;
                m /= 10;
                j *= 10;
            }
            v.push_back({val, i});
        }
        
        sort(v.begin(), v.end(), [&](const pair<int, int>&a, const pair<int, int>&b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        vector<int> ans;
        
        for(auto ele : v) {
            int id = ele.second;
            ans.push_back(nums[id]);
        }
        return ans;
    }
};