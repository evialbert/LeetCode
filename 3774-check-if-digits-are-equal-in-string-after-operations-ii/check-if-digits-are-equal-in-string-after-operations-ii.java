class Solution {
    public boolean hasSameDigits(String s) {
        int size = s.length();
        int X = size - 2;
        int x = 0, y = 0;

        for (int j = 0; j <= X; j++) {
            int coeff = binomialMod10(X, j);
            x = (x + coeff * (s.charAt(j) - '0')) % 10;
            y = (y + coeff * (s.charAt(j + 1) - '0')) % 10;
        }

        return x == y;
    }

    private int binomialMod10(int n, int k) {
        int i = binomialMod2(n, k);
        int j = binomialMod5(n, k);

        for (int x = 0; x < 10; x++) {
            if (x % 2 == i && x % 5 == j) {
                return x;
            }
        }
        return 0;
    }

    private int binomialMod2(int n, int k) {
        return ((n & k) == k) ? 1 : 0;
    }

    private int binomialMod5(int n, int k) {
        int[][] tuples = {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 1, 4, 1}
        };
        int result = 1;

        while (n > 0 || k > 0) {
            int nthd = n % 5;
            int kthd = k % 5;

            if (kthd > nthd) return 0;

            result = (result * tuples[nthd][kthd]) % 5;
            n /= 5;
            k /= 5;
        }
        return result;
    }
}