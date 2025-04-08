class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size();
        for(int i = 1; i < int(nums.size()); i++)
        {
            sum += nums[i];
        }

        return sum - (long long)(n - 1) * nums[0];
    }
};