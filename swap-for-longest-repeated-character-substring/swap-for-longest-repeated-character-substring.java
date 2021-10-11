class Solution {
    public static int maxRepOpt1(String s) {
    int N = s.length(), a = 1;
    int[] c = new int[26];
    for (int i = 0; i < N; i++) {
      int idx = s.charAt(i) - 'a';
      c[idx]++;
      a = Math.max(a, c[idx]);
    }
    if (a == 1) return 1;
    a = 1;
    List<int[]> gs = new ArrayList(N);
    int l = 0;
    while (l < N) {
      int r = l;
      char lc = s.charAt(l);
      while (r < N && s.charAt(r) == lc) r++;
      gs.add(new int[] {l, r - 1});
      l = r;
    }
    for (int i = 0; i < gs.size(); i++) {
      int[] g = gs.get(i);
      int n = g[1] - g[0] + 1;
      char ch = s.charAt(g[0]);
      if (i + 2 < gs.size() && g[1] + 2 == gs.get(i + 2)[0] && ch == s.charAt(gs.get(i + 2)[0])) {
        int[] g2 = gs.get(i + 2);
        int both = n + g2[1] - g2[0] + 1;
        a = Math.max(a, both + (c[ch - 'a'] > both ? 1 : 0));

      } else a = Math.max(a, n + (c[ch - 'a'] > n ? 1 : 0));
    }
    return a;
  }
}