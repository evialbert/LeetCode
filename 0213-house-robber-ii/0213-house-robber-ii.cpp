class Solution {
public:
    int houseRobber(vector<int> &arr) {
        int n = arr.size();
        int prev2 = 0;
        int prev = arr[0];
        int curr;
        for (int i=1; i<n; i++) {
            int pick = arr[i];
            if (i > 1) pick += prev2;
            int notPick = 0 + prev;
            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1(begin(nums), end(nums)-1);
        vector<int> temp2(begin(nums)+1, end(nums));
        return max(houseRobber(temp1), houseRobber(temp2));
    }
};