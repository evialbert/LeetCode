class Solution 
{
    public:
    int maximumGroups(vector<int>& g) 
    {
        int ans = 0;
        for(int i = 1; i < 1000; i++)
        {
            if(g.size() >= (i * (i + 1) / 2))
                ans = i;
        }
    
        return ans;
    }
};