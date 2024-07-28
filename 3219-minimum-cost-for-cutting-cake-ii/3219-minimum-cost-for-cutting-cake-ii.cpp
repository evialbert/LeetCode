class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int vertical = 1, horizontal = 1;
        sort(horizontalCut.begin(), horizontalCut.end());
        reverse(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        reverse(verticalCut.begin(), verticalCut.end());
        int h = 0, v = 0;
        long long ans = 0;
        for (int i=0; i < m + n - 2; ++i) {
            if ((v == verticalCut.size()) || (h != horizontalCut.size() && horizontalCut[h] >= verticalCut[v])) {
            vertical++;
            ans += horizontalCut[h] * horizontal;
            ++h;
            } else {
            horizontal++;
            ans += verticalCut[v] * vertical;
            ++v;
            }
        }
        return ans;
    }
};