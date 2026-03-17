class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> v(1e5+1, 0);
        for(int i = 0; i < n; i++) if(nums[i] != target[i]) v[nums[i]] = 1;
        int count = 0;
        for(int i = 0; i < 1e5+1; i++) count += v[i];
        return count;
    }
};

// 