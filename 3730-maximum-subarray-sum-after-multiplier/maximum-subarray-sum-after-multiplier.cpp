class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=INT_MIN, sum=0, div=0, used=0;
        for(int a:nums){
            used = max(used, div) + a;
            div = max(div, sum) + a/k;
            sum += a;
            ans = max({ans, used, div, sum*k});
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};