class Solution {

    static long[][][][] d;
    static int[] p;
    static String s;

    public long countGoodIntegersOnPath(long l, long r, String t) {
        p = new int[7];

        int a = 0, b = 0, i = 0;
        p[0] = 0;

        while (i < 6) {
            if (t.charAt(i) == 'D')
                a++;
            else
                b++;
            p[i + 1] = a * 4 + b;
            i++;
        }

        return f(r) - f(l - 1);
    }

    static long f(long v) {
        s = String.format("%016d", v);
        d = new long[17][11][2][2];
        return g(0, 0, 1, 0);
    }

    static long g(int i, int p0, int t, int s0) {
        if (i == 16)
            return 1;

        if (d[i][p0][t][s0] != 0)
            return d[i][p0][t][s0] - 1;

        long r = 0;

        int l = (t == 1) ? s.charAt(i) - '0' : 9;

        int k = 0, c = 0;
        while (k < 7) {
            if (p[k] == i) {
                c = 1;
                break;
            }

            k++;
        }

        int j = 0;
        while (j <= l) {
            int nt = (t == 1 && j == l) ? 1 : 0;

            if (c == 1) {
                if (s0 == 1 && j < p0) {
                    j++;
                    continue;
                }

                r += g(i + 1, j, nt, 1);
            } else {
                r += g(i + 1, p0, nt, s0);
            }

            j++;
        }

        d[i][p0][t][s0] = r + 1;
        return r;
    }
}