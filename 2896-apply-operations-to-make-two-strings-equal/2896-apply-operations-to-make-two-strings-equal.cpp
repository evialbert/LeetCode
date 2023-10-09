class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,int n,vector<int> &nums,int x){
        if(i>=n)return 0;
        if(j<0)return 0;
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=nums[i+1]-nums[i]+solve(i+2,j,n,nums,x);
        int b=nums[j]-nums[j-1]+solve(i,j-2,n,nums,x);
        int c=x+solve(i+1,j-1,n,nums,x);
        return dp[i][j]=min(a,min(b,c));
    }
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])continue;
            else temp.push_back(i);
        }
        n=temp.size();
        if(n%2==1)return -1;
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,n,temp,x);
    }
};