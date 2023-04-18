class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        constexpr int MOD = 1000000007;
        std::vector<std::vector<std::vector<int>>> memo(types.size(), std::vector<std::vector<int>>(51, std::vector<int>(1001, -1)));
        
        std::function<int(int, int, int)> dp = [&](int index, int remaining, int sum) -> int {
            if (sum < 0) return 0;
            if (sum == 0) return 1;
            if (index >= types.size()) return 0;
            if (memo[index][remaining][sum] != -1) return memo[index][remaining][sum];
            
            // Try the next item (if one exists)
            int nextItems = 0;
            if (index + 1 < types.size()) {
                nextItems = dp(index + 1, types[index + 1][0], sum);
            }
            
            // Try this item (if we still have remaining items)
            int thisItem = 0;
            if (remaining > 0) {
                thisItem = dp(index, remaining - 1, sum - types[index][1]);
            }
            
            return memo[index][remaining][sum] = (nextItems + thisItem) % MOD;
        };
        
        return dp(0, types[0][0], target);
    }
};