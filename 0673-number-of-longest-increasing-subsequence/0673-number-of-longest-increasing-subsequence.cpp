class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans=1, lon=1, curr, len;
        vector<int> dp(nums.size(),0);
        vector<int> freq(nums.size(),0);
        dp[nums.size()-1] = 1;
        freq[nums.size()-1] = 1;
        for(int i=nums.size()-2; i>=0; --i){
            curr=0, len=0;
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i]<nums[j]){
                    if(dp[j]==len) curr+=freq[j];
                    else if(dp[j]>len) len=dp[j], curr=freq[j];
                }
            }
            if(len==0) dp[i]=1, freq[i]=1;
            else dp[i]=len+1, freq[i]=curr;
            if(dp[i]==lon) ans+=freq[i];
            else if(dp[i]>lon) lon=dp[i], ans=freq[i];
        }
        return ans;
    }
};