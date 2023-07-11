class Solution {
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();

        vector<int> p(n + 1), pp(n);
        for (int i = 0, prev = -1, prev2 = 0; i < n; i++) {
            p[i + 1] = p[i];
            if (boxes[i][0] != prev) {
                p[i + 1]++;
                prev = boxes[i][0];
                prev2 = i;
            }
            pp[i] = prev2;
        }
        
        vector<int> dp(n + 1);
        int weight = 0, k = 0;
        for (int l = n - 1, r1 = n - 1, r2 = n - 1; l >= 0; l--) {
            weight += boxes[l][1];
            k++;
            while (weight > maxWeight || k > maxBoxes) {
                weight -= boxes[r2][1];
                k--;
                r2--;
            }
            r1 = min(r1, r2);
            while (r1 > l && p[r2 + 1] - p[pp[r1]] == 1 && boxes[r1][0] == boxes[r2][0]) {
                r1--;
            }
            assert(r1 >= l);
            assert(r1 <= r2);
            dp[l] = min(p[r1 + 1] - p[pp[l]] + dp[r1 + 1], p[r2 + 1] - p[pp[l]] + dp[r2 + 1]) + 1;
        }
        return dp[0];
    }
};