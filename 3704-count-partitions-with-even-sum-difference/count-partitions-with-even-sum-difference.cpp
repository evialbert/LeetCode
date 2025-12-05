class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return (reduce(nums.begin(), nums.end(), 0)&1)?0:nums.size()-1;
    }
};