class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int count1 = 0, count = 0;
        for (int i = n - 1; i >= 0; i--){
            if(nums[i] != 0){
                ans *= nums[i];
            }
            if(nums[i] < 0){
                count++;
            }
            if(nums[i] == 0){
                count1++;
            }
        }
        if(count == 1 && count1 == n - 1){
            return 0;
        }
        if(count1 == n){
            return 0;
        }
        if(ans < 0){
            for (int i = n - 1; i >= 0; i--){
                if(nums[i] < 0){
                    ans /= nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};