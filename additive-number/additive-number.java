class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        if (n < 3) return false;
        for (int i = 1; i <= n / 2; i++) {
            if (i > 1 && num.charAt(0) == '0') break;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && num.charAt(i) == '0') break;
                long first = Long.parseLong(num.substring(0, i));
                long second = Long.parseLong(num.substring(i, j));
                int k = j;
                while (k < n) {
                    long target = first + second;
                    String s = String.valueOf(target);
                    if (k + s.length() <= n && num.substring(k, k + s.length()).equals(s)) {
                        k += s.length();
                        first = second;
                        second = target;
                    }
                    else break;
                }
                if (k == n) return true;
            }
        }
        return false;
    }
}