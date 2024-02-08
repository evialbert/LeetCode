class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
     long low = 1, high = Integer.MAX_VALUE;
    long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(a, bc);
    
    while (low < high) {
        long mid = (low + high) / 2;
        long count = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
        if (count < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return (int)low;
}

private long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

private long gcd(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
}