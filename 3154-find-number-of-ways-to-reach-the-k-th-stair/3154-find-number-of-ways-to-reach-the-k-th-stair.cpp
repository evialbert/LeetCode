class Solution {
public:
    unsigned long long C(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;

        unsigned long long result = 1;
        for (int i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    int waysToReachStair(int k) {
        // corner cases
        if(k == 0 || k == 4) return 2;
        if(k == 1 || k == 2) return 4;
        int i = 0;
        while((1<<i) < k) ++i;
        k = (1<<i)-k;
        return C(i+1, k);
    }
};