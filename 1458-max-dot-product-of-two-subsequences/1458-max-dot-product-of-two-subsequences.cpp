class Solution {
public:

    long long check(int i,int j,int n,int m,vector<vector<long long >>&dp,vector<int>&nums1,vector<int>&nums2,int flag){
        
        if((i==n || j==m) && flag)return 0;
        if(i==n || j==m)return INT_MIN;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        long long ans=INT_MIN;
        ans=max(ans,check(i+1,j,n,m,dp,nums1,nums2,flag));
        ans=max(ans,check(i,j+1,n,m,dp,nums1,nums2,flag));
        ans=max(ans,nums1[i]*nums2[j]+check(i+1,j+1,n,m,dp,nums1,nums2,flag+1));
        if(nums1[i]*nums2[j]>ans)ans=nums1[i]*nums2[j];
        // cout<<i<<"-"<<j<<"-"<<ans<<"\n";
        return dp[i][j]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,INT_MIN));
        return check(0,0,n,m,dp,nums1,nums2,0);
    }
};