class Solution {
public:
    int dp[1001][1001];
    int find(vector<vector<int>>&nums,int index,int max_width,int width,int height)
    {
        if(width>max_width)
        {
            return 1e8;
        }
        if(index>=nums.size())
        {
            return height;
        }
        if(dp[index][width]!=-1)
        {
            return dp[index][width];
        }
         int w=nums[index][0];
        int h=nums[index][1];
        int same_block=find(nums,index+1,max_width,width+w,max(height,h));
        int new_block=height+find(nums,index+1,max_width,w,h);
        return dp[index][width]=min(same_block,new_block);
    }
    int minHeightShelves(vector<vector<int>>& books, int max_width)
    {   
        memset(dp,-1,sizeof(dp));
        return find(books,0,max_width,0,0);
    }
};