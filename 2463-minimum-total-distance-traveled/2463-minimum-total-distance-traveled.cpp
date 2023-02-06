class Solution {
public:
    static bool cmp(vector<int>& A, vector<int>& B) {
        return A[0] < B[0];
    }
    long long solve(vector<int>& robot, vector<vector<int>>& factory, int robo_pos, int fac_pos, vector<vector<long long>>& dp) {
        if(robot.size() <= robo_pos) {
            return 0;
        }
        if(factory.size() <= fac_pos) {
            return LLONG_MAX;
        }
        if(dp[robo_pos][fac_pos] != -1) {
            return dp[robo_pos][fac_pos];
        }
        long long result = 0, cost = 0, answer = LLONG_MAX;
        int factory_limit = factory[fac_pos][1]; 
        
        result = solve(robot, factory, robo_pos, fac_pos + 1, dp);
        if(result != LLONG_MAX) {
            answer = min(answer, result);
        }
       
        for(int i = robo_pos; i < min(robo_pos + factory_limit, (int)robot.size()); ++i) {
            cost += abs(robot[i] - factory[fac_pos][0]);
            result = solve(robot, factory, i + 1, fac_pos + 1, dp);
            if(result != LLONG_MAX) {
                answer = min(answer, cost + result);
            }
        }

        return dp[robo_pos][fac_pos] = answer;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), cmp);
        int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(robot, factory, 0, 0, dp);
    }
};