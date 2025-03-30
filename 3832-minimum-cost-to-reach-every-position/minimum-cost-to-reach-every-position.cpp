class Solution {
public:
vector<int> minCosts(vector<int>& cost) {
    int minsfr = INT_MAX;
    int n=cost.size();
    for (int i = 0; i < n; i++) {
        minsfr = min(minsfr, cost[i]);
        cost[i] = minsfr; 
    }
    return cost;
}
};