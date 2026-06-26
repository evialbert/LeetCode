class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();

        if(m == 1){
            long long ans = 0;
            for(auto it : units){
                ans += it[0];
            }
            return ans;
        }

        long long sumSeconds = 0;
        long long globalMin = INT_MAX;
        long long minSecond = INT_MAX;

        for(int i = 0; i < n; i++){
            long long firstMin = INT_MAX;
            long long secondMin = INT_MAX;

            for(int j = 0; j < m; j++){
                long long x = units[i][j];

                if(x < firstMin){
                    secondMin = firstMin;
                    firstMin = x;
                }
                else if(x < secondMin){
                    secondMin = x;
                }

                globalMin = min(globalMin, x);
            }

            minSecond = min(minSecond, secondMin);
            sumSeconds += secondMin;
        }

        return sumSeconds - minSecond + globalMin;
    }
};