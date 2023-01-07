class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>runningsum(n);
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            runningsum[i] = sum;
        }
        return runningsum;
    }
};