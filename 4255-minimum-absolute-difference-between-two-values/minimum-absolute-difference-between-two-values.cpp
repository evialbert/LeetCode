class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX, l = -1, r = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                l = i;
            else if(nums[i] == 2)
                r = i;
            if(l != -1 && r != -1)
                ans = min(ans, abs(l-r));
        }
        return (ans == INT_MAX)?-1:ans;
    }
};