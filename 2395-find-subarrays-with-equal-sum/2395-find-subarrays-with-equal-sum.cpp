class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
         map<int,int> mp;

        for(int i=0; i<nums.size()-1; i++)
        {
            int temp=nums[i]+nums[i+1];
            if(mp[temp]==1)
            {
                return true;
            }else{
                mp[temp]++;
            }
        }
        return false;
        
    }
};