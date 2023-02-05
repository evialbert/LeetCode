class Solution {
public:
    int solve(vector<int> &v,int s,int e){
        int n = v.size();
        vector<int> dp(n,0);
        int ans = 0;
        for(int i = s; i <= e; i++){
            if(s==i){
                dp[i] = v[i];
            }else if((s+1) == (i)){
                dp[i] = max(v[i-1],v[i]);
            }else{
                dp[i] = max(v[i]+dp[i-2],dp[i-1]);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        return max(solve(nums,0,nums.size()-2),solve(nums,1,nums.size()-1));
    }
};