class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_e = nums[0], min_e = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int t = max_e;
            max_e = max({max_e * nums[i], min_e * nums[i], nums[i]});
            min_e = min({min_e * nums[i], t * nums[i], nums[i]});
            ans = max(max_e, ans);
        }
        return ans;
    }
};