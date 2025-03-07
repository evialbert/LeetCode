class Solution {
    public boolean isprime(int num) {
        if (num < 2) {
            return false;
        }
        int n = (int) Math.sqrt(num);
        for (int i = 2; i <= n; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    public int[] closestPrimes(int left, int right) {
        int min = Integer.MAX_VALUE;
        int[] ans = {-1, -1};
        int prev = -1;
        for (int l = left; l <= right; l++) {
            if (isprime(l)) { 
                if (prev != -1 && (l - prev < min)) {
                    min = l - prev;
                    ans[0] = prev;
                    ans[1] = l;
                }
                prev = l; 
            }
        }
        return ans;
    }
}