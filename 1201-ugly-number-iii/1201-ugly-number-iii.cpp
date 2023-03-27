class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int lo = 1;
        int hi = 2*(int)1e9;
        
        long A = long(a);
        long B = long(b);
        long C = long(c);
        
        long AB = A*B/__gcd(A,B);
        long BC = B*C/__gcd(B,C);
        long AC = A*C/__gcd(A,C);
        
        long ABC = A*BC/__gcd(A,BC);
        
        while(lo<hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/A + mid/B + mid/C - mid/AB - mid/BC - mid/AC + mid/ABC;
            if(cnt<n)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};