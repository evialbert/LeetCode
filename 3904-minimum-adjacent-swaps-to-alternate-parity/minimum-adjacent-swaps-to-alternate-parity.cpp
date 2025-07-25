class Solution {
public:
    int count(vector<int> nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans += abs(nums[i]-i*2); //since it is bigger, we must start from 0 index, so these will be placed at 0,2,4,6... if it isnt at those index, we need that many swaps with the odd elements
        return ans;
    }
    int minSwaps(vector<int>& nums) 
    {
        vector<int> e,o;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]%2)
                    o.push_back(i);
                else
                    e.push_back(i);
            }
        if(abs((int)o.size()-(int)e.size())>1)
            return -1;
        int ans = INT_MAX;
        if(o.size()>=e.size())
            ans = min(ans,count(o));
        if(e.size() >= o.size())
            ans = min(ans,count(e));
        return ans;
    }
};