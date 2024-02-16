class Solution {
private:
    unordered_map<int,vector<int>>valtoIndex;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            valtoIndex[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        return valtoIndex[target][rand() % valtoIndex[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */