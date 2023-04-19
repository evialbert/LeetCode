class Solution
{
    public:
        int minCostClimbingStairs(vector<int> &cost){
            cost.push_back(0);
            int n = (int) cost.size();
            int prev1, prev2, temp;
            prev1 = 0;
            prev2 = cost[0];
            for (int i = 2; i <= n; ++i)
            {
                temp = min(prev1, prev2) + cost[i - 1];
                prev1 = prev2;
                prev2 = temp;
            }
            return prev2;
        }
};