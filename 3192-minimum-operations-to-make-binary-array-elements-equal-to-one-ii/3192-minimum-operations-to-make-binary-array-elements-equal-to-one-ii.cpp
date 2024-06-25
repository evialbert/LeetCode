class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0;
        int flipped = 0;
        int ans = 0;
        while(i < nums.size()) {
            if(nums[i] == flipped%2) {
                flipped++;
                ans++;
            }
            i++;
        }
        return ans;
    }
};