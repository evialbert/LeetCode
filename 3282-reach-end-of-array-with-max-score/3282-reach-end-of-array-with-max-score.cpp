class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long score = 0;
        int curr = nums[0];
        for(int i = 1;i<nums.size();++i)
        {
            score+=curr;
            if(nums[i]>curr)
                curr = nums[i];
        }
        return score;
    }
};