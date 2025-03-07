class Solution {
public:
int t[2005][2005][2];
int solve(int i,int k,int m,vector<int> &nums,int flag){
    if(t[i][k][flag]!=-1) return t[i][k][flag];
    if(k<=0) return 0;
    if(i>=nums.size()&&flag&&k==1) return 0;
    if(i>=nums.size()) return -1e9;
    
    if(flag){
        return t[i][k][flag]=max(nums[i]+solve(i+1,k,m,nums,true),solve(i,k-1,m,nums,false));
    }      
    
    else{
        if(i+m>nums.size()) return  -1e9;
         int sum = 0;
            for(int j=i; j<i+m; j++){
                sum += nums[j];
            }
         return t[i][k][flag]=max(sum+solve(i+m,k,m,nums,true),solve(i+1,k,m,nums,flag));
    }
}
    int maxSum(vector<int>& nums, int k, int m) {
        memset(t,-1,sizeof(t));
        return solve(0,k,m,nums,false);
    }
};