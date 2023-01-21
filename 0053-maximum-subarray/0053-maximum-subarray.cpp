class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long tempSum = 0;
        long long maxm = nums[0];
        for(long long x: nums){
            tempSum = tempSum + x;
            maxm = max(tempSum, maxm);
            if(tempSum<0){
                tempSum = 0;
            }
        }
        return maxm;
    }
};