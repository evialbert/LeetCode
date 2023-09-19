class Solution {
public:
        long long maximumSum(vector<int>& A) {
        unordered_map<int, long long> count;
        long long res = 0, x, v;
        for (int i = 0; i < A.size(); i++) {
            for (x = i + 1, v = 2; v * v <= x; ++v)
                while (x % (v * v) == 0)
                    x /= v * v;
            res = max(res, count[x] += A[i]);
        }
        return res;
    }
};