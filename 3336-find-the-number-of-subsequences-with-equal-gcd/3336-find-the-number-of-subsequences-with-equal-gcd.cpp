class Solution {
public:
    int dp[201][201][201];
    const int mod = 1000000007;
    int helper(int i, int gcdA, int gcdB, vector<int>& nums) {
        if(i == nums.size()) {
            if(gcdA != 0 && gcdB != 0 && gcdA == gcdB) {
                return 1;
            }
            return 0;
        }
        if(dp[i][gcdA][gcdB] != -1) {
            return dp[i][gcdA][gcdB];
        }
        long long ans = 0LL;
        // Skip this
        ans = helper(i + 1, gcdA, gcdB, nums);
        if(gcdA == 0) {
            ans += helper(i + 1, nums[i], gcdB, nums);
        } else {
            ans += helper(i + 1, __gcd(gcdA, nums[i]), gcdB, nums);
        }
        ans %= mod;
        if(gcdB == 0) {
            ans += helper(i + 1, gcdA, nums[i], nums);
        } else {
            ans += helper(i + 1, gcdA, __gcd(gcdB, nums[i]), nums);
        }
        ans %= mod;
        return dp[i][gcdA][gcdB] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, nums);
    }
};