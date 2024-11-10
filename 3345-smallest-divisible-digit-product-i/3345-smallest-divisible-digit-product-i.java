class Solution {
    public int smallestNumber(int n, int t) {
        while(true) {
            int dp = digitProd(n);
            if(dp % t == 0)
                return n;
            n++;
        }
    }
    static int digitProd(int n) {
        int res = 1;
        while(n > 0) {
            res *= (n % 10);
            n /= 10;
        }
        return res;
    }
}