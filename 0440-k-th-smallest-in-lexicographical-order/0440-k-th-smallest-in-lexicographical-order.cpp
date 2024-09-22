class Solution {
public:
    int Count(long curr, long next, int n) {
        long countnum = 0;
        while (curr <= n) {
            countnum += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, (long)n + 1);
        }
        return countnum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while (k > 0) {
            int count = Count(curr, curr + 1, n);
            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};