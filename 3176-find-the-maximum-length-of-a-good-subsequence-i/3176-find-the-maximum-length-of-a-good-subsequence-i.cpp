class Solution {
public:
    int dp[600][600][50];
    int f(int i,int p,int cnt,int k,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i][p+1][cnt]!=-1) return dp[i][p+1][cnt];
        int ans=0;
        if(p==-1){
            ans=max(ans,1+f(i+1,i,cnt,k,nums));
            ans=max(ans,f(i+1,p,cnt,k,nums));
        } else {
            if(nums[p]==nums[i]){
            ans=max(ans,1+f(i+1,i,cnt,k,nums));  
            } else {
            ans=max(ans,f(i+1,p,cnt,k,nums));
            if(k>cnt){
            ans=max(ans,1+f(i+1,i,cnt+1,k,nums));     
            }    
            }
        }
        return dp[i][p+1][cnt]=ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0,-1,0, k, nums); 
    }
};