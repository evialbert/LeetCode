class Solution {
    public int monotoneIncreasingDigits(int N) {
        int[] memo = new int[10];
        int num = 1_000_000_000;
        for (int i = 9; i >= 0; i--) {
            if (N / num > 0) {
                memo[i] = N / num;
                N %= num;
            }
            num /= 10;
        }
        for (int i = 9; i >= 1; i--) {
            if (memo[i] > memo[i - 1]) {
                memo[i]--;
                while (i <= 8) {
                    if (memo[i] >= memo[i + 1]) {
                        break;
                    } else {
                        memo[++i]--;
                    }
                }
                while (--i >= 0) {
                    memo[i] = 9;
                }
            }
        }
        int res = 0;
        int base = 1;
        for (int m: memo) {
            res += m * base;
            base *= 10;
        }
        return res;
    }
}