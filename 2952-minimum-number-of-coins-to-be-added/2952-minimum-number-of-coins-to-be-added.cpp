class Solution {
public:
    int minimumAddedCoins(vector<int>& nums, int n) {
        int addition = 0, idx = 0;
        long long curr_max = 1;
        sort(nums.begin(), nums.end());
        while(curr_max<=n){
            if(idx<nums.size() && nums[idx]<=curr_max){
                curr_max += nums[idx];
                idx++;
            }
            else{
                curr_max += curr_max;
                addition++;
            }

        }
        return addition;

    }
};