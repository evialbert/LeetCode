class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = abs(nums[0]-nums.back());
        for(int i = 1; i < nums.size(); i++)
            maxDiff = max(maxDiff, abs(nums[i]-nums[i-1])); 
        return maxDiff;
    }
};