class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            long long diff=abs((long long)nums[i]-(long long)nums[i-1]);
            if(ans>diff)
            {
                ans=diff;
            }
        }
        return ans;
    }
};