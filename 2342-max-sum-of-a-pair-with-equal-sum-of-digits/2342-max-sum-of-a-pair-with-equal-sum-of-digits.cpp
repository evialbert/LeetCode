class Solution {
public:
    int sod(int x)
    {
        int ans=0;
        while(x>0)
        {
            ans+=x%10;
            x=x/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(auto i:nums)
        {
            int a=sod(i);
            mp[a].push(i);
            if(mp[a].size()>2)mp[a].pop();
        }
        int ans=-1;
        for(auto i:mp)
        {
            if(i.second.size()==2)
            {
                int x=i.second.top();
                i.second.pop();
                int y=i.second.top();
                i.second.pop();
                ans=max(ans,x+y);
            }
        }
        return ans;
    }
};