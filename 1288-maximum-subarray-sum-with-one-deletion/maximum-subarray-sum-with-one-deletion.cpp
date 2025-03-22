class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), res = -1e4;
        vector<int> maxFromR(n, 0), maxFromL(n, 0);
        for (int i = 0; i < n; ++ i) {
            maxFromL[i] = max(arr[i], (i ? maxFromL[i - 1] + arr[i] : -10000));
            res = max(res, maxFromL[i]);
        } 
        for (int i = n - 1; i >= 0; -- i) {
            maxFromR[i] = max(arr[i], (i < n - 1 ? maxFromR[i + 1] + arr[i] : -10000));
            res = max(res, maxFromR[i]);
        }
        for (int i = 1; i < n - 1; ++ i) {
            res = max(res, maxFromL[i - 1] + maxFromR[i + 1]);
        }
        return res;
    }
};