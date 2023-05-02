class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n);
        vector<long long> conver(n);
        conver[0] = 2*nums[0];
        int mx = nums[0];
        for(int i=1; i<n; i++){
            mx = max(mx, nums[i]);
            conver[i] = nums[i] +0ll+ mx;
        }
        ans[0]=conver[0];
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + 0ll+conver[i];
        }
        return ans;
    }
};