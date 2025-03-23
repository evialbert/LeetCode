class Solution {

    public int numberOfComponents(int[][] properties, int k) {
        final int n = properties.length;
        // 1) Determine the n sets as Bits100 objects.
        final Bits100[] props = new Bits100[n];
        for (int i = 0; i < n; ++i) {
            Bits100 b = new Bits100(properties[i][0]);
            for (int j = 1; j < properties[i].length; ++j) {
                b = b.or(new Bits100(properties[i][j]));
            }
            props[i] = b;
        }
        // 2) Find edges and union them in the DSU.
        final DSU dsu = new DSU(n);
        for (int i = 0; i < n; ++i) {
            for (int j = (i + 1); j < n; ++j) {
                if (props[i].and(props[j]).bitCount() >= k) {
                    dsu.union(i, j);
                }
            }
        }
        // 3) Count the unique parents for the answer.
        final Set<Integer> unique = new LinkedHashSet<>();
        for (int i = 0; i < n; ++i) {
            unique.add(dsu.find(i));
        }
        return unique.size();
    }

    static class DSU {

        private final int[] parents;

        public DSU(int n) {
            this.parents = new int[n];
            for (int i = 0; i < n; ++i) {
                this.parents[i] = i;
            }
        }

        public final int find(int x) {
            if (this.parents[x] == x) {
                return x;
            }
            this.parents[x] = find(this.parents[x]);
            return this.parents[x];
        }

        public final void union(int x, int y) {
            final int px = find(x);
            final int py = find(y);
            if (px != py) {
                this.parents[py] = px;
            }
        }
    }

    static class Bits100 {

        final long upper50;
        final long lower50;

        public Bits100(int value) {
            if (value < 1 || value > 100) {
                throw new IllegalArgumentException("out of bounds: " + value);
            }
            final int v = value - 1;
            this.lower50 = (v < 50 ? (1L << v) : 0L);
            this.upper50 = (v < 50 ? 0L : (1L << (v - 50)));
        }

        private Bits100(long lower50, long upper50) {
            this.lower50 = lower50;
            this.upper50 = upper50;
        }

        public Bits100 and(Bits100 other) {
            return new Bits100(this.lower50 & other.lower50, this.upper50 & other.upper50);
        }

        public Bits100 or(Bits100 other) {
            return new Bits100(this.lower50 | other.lower50, this.upper50 | other.upper50);
        }

        public int bitCount() {
            return Long.bitCount(this.lower50) + Long.bitCount(this.upper50);
        }
    }
}