class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);

        for (const vector<int>& relation : relations) {
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }

        vector<int> memo(n, -1);

        function<int(int)> calculateTime = [&](int course) {
            if (memo[course] != -1) {
                return memo[course];
            }

            int maxPrerequisiteTime = 0;
            for (int prereq : graph[course]) {
                maxPrerequisiteTime = max(maxPrerequisiteTime, calculateTime(prereq));
            }

            memo[course] = maxPrerequisiteTime + time[course];
            return memo[course];
        };

        int overallMinTime = 0;
        for (int course = 0; course < n; course++) {
            overallMinTime = max(overallMinTime, calculateTime(course));
        }

        return overallMinTime;
    }
};