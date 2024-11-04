class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> arriveAt(n, vector<int>(m, INT_MAX));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        arriveAt[0][0] = 0;

        int dirs[] = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [curTime, y, x] = pq.top();
            pq.pop();

            if (y == n - 1 && x == m - 1) {
                return curTime;
            }

            for (int k = 0; k < 4; ++k) {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == n || dx < 0 || dx == m) {
                    continue;
                }

                int newTime = max(moveTime[dy][dx] + 1, curTime + 1);
                if (newTime < arriveAt[dy][dx]) {
                    arriveAt[dy][dx] = newTime;
                    pq.push({newTime, dy, dx});
                }
            }
        }

        return -1;
    }
};