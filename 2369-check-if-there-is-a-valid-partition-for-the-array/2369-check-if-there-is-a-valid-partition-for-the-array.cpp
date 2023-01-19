class Solution {
public:
    bool isvalid(int i,int j,vector<int>&nums)
    {
        if(j+i-1 == 2) return nums[i]==nums[j];
        else if(nums[i]== nums[i+1] and nums[i+1]==nums[j]) return true;
        else if(nums[i+1]-nums[i]==1 and nums[j]-nums[i+1]==1) return true;
        return false;
    }
    bool backtrack(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==nums.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        bool pos1=false;
        bool pos2=false;
        if(ind+1<nums.size() and isvalid(ind,ind+1,nums))
        {
            pos1=backtrack(ind+2,nums,dp);
        }
        if(ind+2<nums.size() and isvalid(ind,ind+2,nums))
        {
            pos2=backtrack(ind+3,nums,dp);
        }
        return dp[ind]=pos2||pos1;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return backtrack(0,nums,dp);
    }
};
