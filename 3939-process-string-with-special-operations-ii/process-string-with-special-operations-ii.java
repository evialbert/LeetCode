class Solution {
    public char processStr(String s, long k) {

        char[] a = s.toCharArray();
        long totalLen = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == '*') {
                if (totalLen >= 1)
                    totalLen -= 1;
            } else if (a[i] == '#') {
                totalLen = totalLen + totalLen;
            } else if (a[i] == '%') {

            } else {
                totalLen++;
            }
        }

        if (k >= totalLen)
            return '.';

        for (int i = a.length - 1; i >= 0; i--) {
            if (a[i] == '*') {
                totalLen += 1;
            } else if (a[i] == '#') {
                if (k >= totalLen / 2) {
                    k -= totalLen / 2;
                }
                totalLen = totalLen / 2;
            } else if (a[i] == '%') {
                k = (totalLen - 1) - k;
            } else {
                if (k == totalLen - 1) {
                    return a[i];
                }
                totalLen -= 1;
            }
        }
        return '.';
    }
}