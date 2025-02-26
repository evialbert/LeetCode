class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // solving it using the kadane's algorithm
        int maxend = nums[0];
        int maxresult = nums[0];
        for(int i = 1; i< nums.size(); i++)
        {
            maxend += nums[i];
            maxend = max(maxend, nums[i]);
            maxresult = max(maxend, maxresult);
        }

        int minend = nums[0];
        int minresult = nums[0];
        for(int i=1; i< nums.size();  i++)
        {
            minend += nums[i];
            minend = min(minend, nums[i]);
            minresult = min(minresult, minend);
        }

        int answer = max(abs(minresult), abs(maxresult));
        return answer;

    }
};