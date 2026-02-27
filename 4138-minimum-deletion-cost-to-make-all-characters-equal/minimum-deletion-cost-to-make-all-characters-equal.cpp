class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long hash[26] = {0};
        long long total_cost = 0 , max_cost = 0;
        for(int i = 0; i < cost.size(); i++) {
            total_cost += cost[i];
            hash[s[i] - 'a'] += cost[i];
            if(hash[s[i] - 'a'] > max_cost) max_cost = hash[s[i] - 'a'];
        }
        return total_cost - max_cost;
    }
};