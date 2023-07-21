class Solution {
public:
    vector<int>dp[100009];
    vector<int>vis=vector<int>(100009,0);
    void find(int x,vector<int>&nums)
    {
        if(vis[nums[x]])
        {
            return ;
        }
        vis[nums[x]]=1;
        for(auto it:dp[x])
        {
            find(it,nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& pt, vector<int>& nums) 
    {    
        for(int i=1;i<pt.size();i++)
        {
            dp[pt[i]].push_back(i);
        }
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                index=i;
                break;
            }
        }
        int element=1;
        vector<int>ans(nums.size(),1);
        while(index>-1)
        {
            find(index,nums);
            while(vis[element])
            {
                element++;
            }
            ans[index]=element;
            index=pt[index];
        }
        return ans;
    }
};