class Solution {
public:
    // ans is [(r-l+1)^(k-1)][sum of all numbers][10^k-1][invese mod of 9]
    long long modPow(long long x, long long y, long long p) {
        long long result = 1;
        x = x % p;

        while (y > 0) {
            if (y & 1)           // if current bit is 1
                result = (result * x) % p;

            x = (x * x) % p;     // square the base
            y >>= 1;             // divide y by 2
        }
        return result;
    }
    int sumOfNumbers(int l, int r, int k) {
        long long mod = 1000000007;
        //inverse mod of 9 = 111111112

        long long t1=modPow(r-l+1, k-1, mod);
        long long t2=0;
        for(int i=l;i<=r;i++)t2+=i;
        long long t4=111111112;
        long long t3=(modPow(10, k, mod)-1+mod)%mod;
        return ((t1*t2)%mod)*((t3*t4)%mod)%mod;

    }
};