class Solution {
public:
   int minWastedSpace(vector<int>& A, vector<vector<int>>& boxes) {
        sort(A.begin(), A.end());
        long res = LONG_MAX, mod = 1e9 + 7, sumA = 0;
        for (int a : A)
            sumA += a;
        for (auto& B : boxes) {
            sort(B.begin(), B.end());
            if (B[B.size() - 1] < A[A.size() - 1]) continue;
            long cur = 0, i = 0, j;
            for (int b : B) {
                j = upper_bound(A.begin() + i, A.end(), b) - A.begin();
                cur += b * (j - i);
                i = j;
            }
            res = min(res, cur);
        }
        return res < LONG_MAX ? (res - sumA) % mod : -1;
    }
};