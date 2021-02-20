class Solution {
    public int countDigitOne(int n) {
        long rt = 0;
        for (long i = 1; i <= n; i *= 10) {
            long first = n / i, second = n % i;
            long mid = first % 10;
            if (mid == 0) {
                rt += first / 10 * i;
            }else if (mid == 1) {
                rt += first / 10 * i + second + 1;
            }else {
                rt += (first / 10 + 1) * i;
            }
        }
        
        return (int)rt;
    }
}