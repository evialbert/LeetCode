class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<vector<long long>> dp(n+1,vector<long long>(k,0));  

        for(int i=0; i<n; i++){
            int m = nums[i]%k;
            dp[i+1][m]++;

            for(int rem=0; rem<k; rem++){
                int tofill = (rem*m)%k;
                dp[i+1][tofill]+=dp[i][rem];
            }  

            for(int rem =0 ; rem<k; rem++)ans[rem]+=dp[i+1][rem];
        }

        return ans;
    }
};