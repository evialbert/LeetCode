class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        sort(costs.begin(),costs.end(),[](auto &x, auto &y){return x[0]-x[1]<y[0]-y[1];});
        int n = costs.size();
        int n_A = n/2;
        int sum = 0;
        for(int i = 0; i<n;++i)
        {
            if(i<n_A)
            {
                sum += costs[i][0];
            }
            else
            {
                sum += costs[i][1];
            }
        }
        return sum;
        
    }
};