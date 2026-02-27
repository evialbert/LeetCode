class Solution {
public:
    int reverse(int n) {
        int r = 0;
        while (n) {
            int d = n % 10;
            r = r * 10 + d;
            n /= 10;
        }
        return r;
    }
    int mirrorDistance(int n) { return abs(n - reverse(n)); }
};