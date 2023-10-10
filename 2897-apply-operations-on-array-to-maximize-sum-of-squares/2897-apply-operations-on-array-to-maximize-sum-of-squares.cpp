class Solution {
public:
    int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bc(32, 0);
        for(auto i : nums){
            for(int j = 0; j < 32; ++j){
                if(((i >> j) & 1) == 1) bc[j]++;
            }
        }
        
        int ans = 0;
        while(k--){
            long long num = 0;
            for(int i = 0; i < 32; ++i){
                if(bc[i] >= 1){
                    num |= (1 << i);
                    bc[i]--;
                }
            }
            ans = (ans + (num*num)%mod)%mod;
        }
        return ans;
    }
};