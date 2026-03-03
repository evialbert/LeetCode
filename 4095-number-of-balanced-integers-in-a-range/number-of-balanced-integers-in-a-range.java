class Solution {

    long[][][][] d;
    char[] a;
    int n;

    long f(int i, int s, int p, int t) {
        if (i == n)
            return (p >= 2 && s == 0) ? 1 : 0;

        if (d[i][s + 135][p][t] != -1)
            return d[i][s + 135][p][t];

        long r = 0;
        int u = t == 1 ? a[i] - '0' : 9;

        for (int x = 0; x <= u; x++) {
            int np = p + (x != 0 ? 1 : 0);
            int ns = s;

            if (x != 0) {
                int pos = n - i;
                if ((pos & 1) == 1)
                    ns += x;
                else
                    ns -= x;
            }

            r += f(i + 1, ns, np, (t == 1 && x == u) ? 1 : 0);
        }

        return d[i][s + 135][p][t] = r;
    }

    long g(long x) {
        if (x < 10)
            return 0;
        a = Long.toString(x).toCharArray();
        n = a.length;
        d = new long[n][271][n + 1][2];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 271; j++)
                for (int k = 0; k <= n; k++)
                    for (int t = 0; t < 2; t++)
                        d[i][j][k][t] = -1;

        return f(0, 0, 0, 1);
    }

    public long countBalanced(long low, long high) {
        long xy = low;
        return g(high) - g(xy - 1);
    }
}