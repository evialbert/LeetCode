class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int sq=sqrt(nums[i]);
            if(sq*sq!=nums[i])
            {
                mp[nums[i]]=1;
                continue;
            }
            if(mp.count(sq))
            {
                mp[nums[i]]=mp[sq]+1;
            }
            else mp[nums[i]]=1;
            
        }
        int ans=-1e9;
        for(auto it:mp)
        {
            ans=max(ans,it.second);
        }
        return ans==1?-1:ans;
    }
};