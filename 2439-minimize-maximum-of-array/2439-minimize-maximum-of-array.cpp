class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
         long long sum = 0,ans=0;int n=nums.size();
        for (int i = 0; i< n; i++) {
            sum += nums[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return (int) ans;
    }
};