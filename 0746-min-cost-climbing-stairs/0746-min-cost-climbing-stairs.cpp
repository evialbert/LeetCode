class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        cost.push_back(0);
        for (int i = cost.size() - 3; i >= 0; --i) {
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }
        return std::min(cost[0], cost[1]);
    }
};