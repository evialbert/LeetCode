class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n = nums.size();

        bitset<100001> dp, validPrev, mask;

        // with sum 0 --> yes exist, empty set
        // dp is the dp array, link with that
        // dp[ind] --> that possible ind sum can be made given we have reached at some point in nums array
        sort(nums.begin(), nums.end());

        dp[0] = 1;
        int maskId = 0;
        for(int i = 0; i < n; i++){
            // create mask
            while(maskId < nums[i]){
                mask[maskId] = 1;
                maskId++;
            }

            validPrev = dp & mask;

            dp |= (validPrev << nums[i]);
        }

        // since we need max sum, we will iterate from left in dp array
        // whenever we see a 1, that i is our ans

        int ind = 1e5;

        while(dp[ind] == 0){
            ind--;
        }

        return ind;


    }
};