class Solution {
public:
    vector<int> constructTransformedArray(const vector<int>& nums) {
        const int len = size(nums);
        vector<int> res(len);
        for(int i = 0; i < len; ++i)
            res[i] = nums[nums[i]? (i + len + nums[i] % len) % len: i];
        return res;
    }
};