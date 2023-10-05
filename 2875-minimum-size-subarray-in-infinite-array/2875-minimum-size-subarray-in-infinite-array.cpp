class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size(), minLen = INT_MAX, res=0, sum = 0, st = 0;
        for(int i{}; i<n; i++){

            // Calculate the sum, it might overflow so just sum until it is less that or equal to target
            if(sum <= target)
                sum += nums[i];
            nums.push_back(nums[i]);
        }

        res = n * (target / sum);
        target %= sum;
        n = nums.size();
        sum = 0;

        for(int end = 0; end < n; end++) {
            sum += nums[end];
            while(sum > target) {
                sum -= nums[st++];
            }
            
            if(sum == target) {
                int len = end - st + 1;
                minLen = min(minLen, len);
            }
        }
        if(minLen == INT_MAX) return -1;
        res += minLen;
        return res;
    }
};