class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=1;
        int mn=nums[0];
        int mx=nums[0];
        for(int i=1;i<n;i++)
        {
            mn=min(nums[i],mn);
            mx=max(nums[i],mx);
            if(mx-mn<=k)
            {
                continue;
            }
            else
            {
                count++;
                mn=nums[i];
                mx=nums[i];
            }
        }
        return count;
    }
};