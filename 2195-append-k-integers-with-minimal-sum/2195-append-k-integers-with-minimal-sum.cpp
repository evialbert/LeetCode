class Solution {
public:
    long long minimalKSum(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long ans = 0, N = A.size();
        for (int i = 0; i < N && k; ++i) {
            long prev = i == 0 ? 0 : A[i - 1]; // the previous number
            long cnt = min((long)k, max((long)0, A[i] - prev - 1)); // the count of missing numbers between `prev` and `A[i]`
            k -= cnt; // use these `cnt` missing numbers
            ans += (long)(prev + 1 + prev + cnt) * cnt / 2; // sum of these `cnt` missing numbers `[prev+1, prev+cnt]`.
        }
        if (k > 0) ans += ((long)A.back() + 1 + A.back() + k) * k / 2; // If there are still missing numbers, add the sum of numbers`[A.back()+1, A.back()+k]` to answer
        return ans;
    }
};