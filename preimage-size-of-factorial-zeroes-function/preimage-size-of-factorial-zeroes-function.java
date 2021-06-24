class Solution {
    public int preimageSizeFZF(int K) {
        long left = 0;
        long right = 5L * (long)K;
        while (left < right) {
            long mid = left + (right - left) / 2L;
            int cnt = f(mid);
            if (cnt < K) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (left == right && f(left) == K) {
            return 5;
        }
        return 0;
    }
    
    private int f(long x) {
        int cnt = 0;
        for (long i = 5L; i <= x; i = i * 5L) {
            cnt += (int)(x / i);
        }
        return cnt;
    }
}