class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==(nums[i-1]+1))
            {
                sum+=nums[i];
            }
            else break;
        }
        while(mp[sum]>0)
        {
            sum++;
        }
        return sum;
    }
};