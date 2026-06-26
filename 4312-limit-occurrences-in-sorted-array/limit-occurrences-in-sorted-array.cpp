class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            {
                mp[nums[i]]++;
            }

        for(int i=0;i<n;i++)
            {
                if(mp.find(nums[i])!=mp.end())
                {
                for(int j=0;j<min(mp[nums[i]],k);j++)
                    {
                     ans.push_back(nums[i]);
                    }
                }
                mp.erase(nums[i]);
            }
        return ans;
        
    }
};