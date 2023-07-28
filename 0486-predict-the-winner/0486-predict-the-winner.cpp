class Solution {
public:
    vector<vector<int>>dp;
    bool PredictTheWinner(vector<int>& nums) {
        int total_score=0;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        for(int i=0;i<nums.size();i++)
        {
            total_score+=nums[i];
        }
        int p1_score=fun(nums,0,nums.size()-1);
        int p2_score=total_score-p1_score;
        if(p2_score>p1_score)
            return false;
        return true;
    }
    int fun(vector<int>&nums,int start,int end)
    {
        if(start>end)
        {
            return 0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        int choise1=nums[start]+min(fun(nums,start+2,end),fun(nums,start+1,end-1));
        int choise2=nums[end]+min(fun(nums,start+1,end-1),fun(nums,start,end-2));
        return dp[start][end]=max(choise1,choise2);
    }
};