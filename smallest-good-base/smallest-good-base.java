public class Solution {
    public String smallestGoodBase(String n) {
        long nlongval = Long.parseLong(n);
        assert 3 <= nlongval && nlongval <= (long) Math.pow(10, 18);
        int mindigits = 2;
        int maxdigits = (int) (Math.log(nlongval + 1) / Math.log(2));
        for (int digits = maxdigits; digits >= mindigits; digits--) {
            long minbase = (long)(Math.pow(nlongval + 1, 1D / digits));
            long maxbase = (long)(Math.pow(nlongval, 1D / (digits - 1)));
            while (minbase <= maxbase) {
                long base = minbase + (maxbase - minbase) / 2;
                long candidate = 0L;
                for (int i = 0; i < digits; i++) {
                    candidate = candidate * base + 1;
                }
                if (candidate == nlongval) {
                    return Long.toString(base);
                } else if (candidate < nlongval) {
                    minbase = base + 1;
                } else {
                    maxbase = base - 1;
                }
            }
        }
        return String.valueOf(nlongval - 1);
    }
}