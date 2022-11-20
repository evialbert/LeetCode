class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> numZeroesLeft (n, 0); // numZeroesLeft[i] = number of zeroes to the left of i (exclusive).
        vector<int> numZeroesRight (n, 0); // numZeroesRight[i] = number of zeroes to the right of i (exclusive).
        
        for (int i = 1; i < n; i++) {
            numZeroesLeft[i] = numZeroesLeft[i - 1];
            if (s[i - 1] == '0') {
                numZeroesLeft[i]++;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            numZeroesRight[i] = numZeroesRight[i + 1];
            if (s[i + 1] == '0') {
                numZeroesRight[i]++;
            }
        }
        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1') {
                // 0 1 0: find the number of zeroes on either side of this 1.
                ans += numZeroesLeft[i] * numZeroesRight[i];
            } else {
                // 1 0 1: find the number of ones on the left and right of this 0.
                int onesLeft = i - numZeroesLeft[i];
                int onesRight = n - 1 - i - numZeroesRight[i];
                ans += onesLeft * onesRight;
            }
        }
        
        return ans;
        
    }
};