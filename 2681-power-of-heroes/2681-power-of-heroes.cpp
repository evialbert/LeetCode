class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;
        long long res = (((1LL*nums[0]*nums[0])%mod)*nums[0])%mod, m = nums[0];
        for(int i=1; i<nums.size(); ++i){
            m = ((m*2)%mod)-nums[i-1]+nums[i];
            res = (res + (((1LL*nums[i]*nums[i])%mod)*m)%mod)%mod;
        }
        return res;
    }
};