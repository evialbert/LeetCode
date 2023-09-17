class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            maxi=max(maxi,x.second);
        }
        int ans=2*maxi-n;
        if(ans>0)
            return ans;
        else
            return abs(ans)&1;
    }
};