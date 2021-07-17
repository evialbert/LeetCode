class Solution {
    public String pushDominoes(String S) {
        char[] c = S.toCharArray();
        for (int i = 0; i < c.length; i++) {
            if (c[i] == 'L' || c[i] == 'R') continue;
			// mark start index of the substring filled with '.'
            int l = i;
            int r = i;
			// mark end index of the substring filled with '.'
            while (i < c.length && c[i] == '.') {
                r = i++;
            }
			// resolve the substring between l and r;
            while (l <= r) {
                boolean found = false;
                // only one point with 'R' / 'L' neighbours
                if (l > 0 && r < c.length - 1 && r == l && c[l - 1] == 'R' && c[r + 1] == 'L')
                    break;
                if (l > 0 && c[l - 1] == 'R') {
                    c[l] = 'R';
                    l++;
                    found = true;
                }
                if (r < c.length - 1 && c[r + 1] == 'L') {
                    c[r] = 'L';
                    r--;
                    found = true;
                }
                // need to break here to avoid infinit loop
                if (!found) break;
            }
        }
        return new String(c);
    }
}