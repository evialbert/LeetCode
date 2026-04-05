class Solution {
    public int almostPalindromic(String s) {
        int ans = 0;
        int n = s.length();

        for (int i=0; i<n; i++) {
            int left_odd = check_l_odd(i, s);
            int right_odd = check_r_odd(i, s);

            int odd = Math.max(left_odd, right_odd);

            int left_even = check_l_even(i, s);
            int right_even = check_r_even(i, s);

            int even = Math.max(left_even, right_even);

            ans = Math.max(ans, Math.max(odd, even));
        }

        return ans;
    }

    public int check_l_odd(int i, String s) {
        int curr = 1;
        int n = s.length();
        boolean change = false;

        int x = i-1;
        int y = i+1;

        while (x > -1 && y < n) {
            if (s.charAt(x) == s.charAt(y)) {
                curr = curr + 2;
                x--;
                y++;
            } else if (!change) {
                curr++;
                x--;
                change = true;
            } else {
                break;
            }
        }

        if (!change && curr < n) curr++;

        return curr;
    }

    public int check_r_odd(int i, String s) {
        int curr = 1;
        int n = s.length();
        boolean change = false;

        int x = i-1;
        int y = i+1;

        while (x > -1 && y < n) {
            if (s.charAt(x) == s.charAt(y)) {
                curr = curr + 2;
                x--;
                y++;
            } else if (!change) {
                curr++;
                y++;
                change = true;
            } else {
                break;
            }
        }

        if (!change && curr < n) curr++;

        return curr;
    }

    public int check_l_even(int i, String s) {
        int curr = 0;
        int n = s.length();
        boolean change = false;

        int x = i;
        int y = i+1;

        while (x > -1 && y < n) {
            if (s.charAt(x) == s.charAt(y)) {
                curr = curr + 2;
                x--;
                y++;
            } else if (!change) {
                curr++;
                x--;
                change = true;
            } else {
                break;
            }
        }

        if (!change && curr < n) curr++;

        return curr;
    }

    public int check_r_even(int i, String s) {
        int curr = 0;
        int n = s.length();
        boolean change = false;

        int x = i;
        int y = i+1;

        while (x > -1 && y < n) {
            if (s.charAt(x) == s.charAt(y)) {
                curr = curr + 2;
                x--;
                y++;
            } else if (!change) {
                curr++;
                y++;
                change = true;
            } else {
                break;
            }
        }

        if (!change && curr < n) curr++;

        return curr;
    }
}