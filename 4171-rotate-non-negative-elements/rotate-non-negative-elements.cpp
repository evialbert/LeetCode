class Solution {
    void rotateArray(vector<int>& nums, int k){
        vector<int> v;
        int n = nums.size();
        for(int i = k; i < n; i++)v.push_back(nums[i]);
        for(int i = 0; i < k; i++)v.push_back(nums[i]);
        nums = v;
    }
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        if(k == 0 || nums.size() == 1) return nums;
        int n = nums.size();
        for(int i = 0; i < n; i++) if(nums[i] >= 0)v.push_back(nums[i]);
        if(v.size() == 0 || v.size() == 1) return nums;
        k = k%(v.size());
        rotateArray(v, k);
        int idx = 0;
        for(int i = 0; i < n; i++)if(nums[i] >= 0)nums[i] = v[idx++];
        return nums;
    }
};