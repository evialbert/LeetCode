class Solution {
public:
    vector<bool> sieve_of_Eratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    int largestPrime(int n) {
        if (n < 2) return 0;

        vector<bool> isPrime = sieve_of_Eratosthenes(n);

        long long sum = 0;
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                sum += i;

                if (sum > n) break;           
                if (isPrime[sum]) ans = sum; 
            }
        }

        return ans;
    }
};