class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n<k && m<k) {
            return 0;
        }
        int maxLog = max(n, m);
        long long len1 = maxLog-k;
        long long len2 = maxLog-len1;
        return (long long) len1*len2;
    }
};