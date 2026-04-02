class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<long long>>>dp(nums1.size(),vector<vector<long long>>(nums2.size(),vector<long long>(k,INT64_MIN)));
        dp[0][0][0]=1LL*nums1[0]*nums2[0];
        for(int i=1;i<nums1.size();i++)
            dp[i][0][0]=max(dp[i-1][0][0],1LL*nums1[i]*nums2[0]);
        for(int j=1;j<nums2.size();j++)
            dp[0][j][0]=max(dp[0][j-1][0],1LL*nums1[0]*nums2[j]);
        for(int i=1;i<nums1.size();i++){
            for(int j=1;j<nums2.size();j++){
                for(int k1=0;k1<k;k1++){
                    if(k1>i || k1>j)
                    break;
                    dp[i][j][k1]=max(dp[i-1][j][k1],dp[i][j-1][k1]);
                    if(k1>0)
                        dp[i][j][k1]=max(dp[i][j][k1],dp[i-1][j-1][k1-1]+1LL*nums1[i]*nums2[j]);
                    else
                        dp[i][j][k1]=max(dp[i][j][k1],1LL*nums1[i]*nums2[j]);
                }
            }
        }
        return dp[nums1.size()-1][nums2.size()-1][k-1];
    }
};