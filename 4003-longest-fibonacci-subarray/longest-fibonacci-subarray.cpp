class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int len = 2;
        int currLen = 2;
        for(int i = 2; i < n; i++) {

            if((1LL*nums[i]) == (1LL*nums[i - 1] + 1LL*nums[i - 2])) {
                currLen++;
            }
            else {
                currLen = 2;
            }
            len = max(len, currLen);
        }

        return len;
    }
};