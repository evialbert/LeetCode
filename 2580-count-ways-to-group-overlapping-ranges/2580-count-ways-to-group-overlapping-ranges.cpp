class Solution 
{
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        sort(ranges.begin(), ranges.end());
        int total = 1, maxi_range=ranges[0][1];
        for(int i=1; i<ranges.size(); i++)
        {
            if(ranges[i][0] > maxi_range) total++;
            maxi_range = max(maxi_range, ranges[i][1]);
        }
        
        int ways=1, mod=1e9+7;
        while(total--)
        {
            ways = (ways*2)%mod;
        }
        return ways;
    }
};