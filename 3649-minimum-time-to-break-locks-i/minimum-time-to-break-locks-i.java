class Solution {
    public int k, n, ans;
    public List<Integer> strength;
    public boolean[] visited;

    public void solve(final int i, final int x, final int cur) {
        if (i == n) {
            ans = Integer.min(ans, cur);

            return;
        }

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = true;

                final int curStrength = strength.get(j);
                final int curMinutes = (curStrength / x) + (curStrength % x != 0 ? 1 : 0);

                this.solve(i + 1, x + k, cur + curMinutes);

                visited[j] = false;
            }
        }
    }

    public int findMinimumTime(List<Integer> strength, int K) {
        this.k = K;
        this.ans = (int) 1e9;
        this.n = strength.size();
        this.strength = strength;    
        this.visited = new boolean[n];

        this.solve(0, 1, 0);

        return ans;
    }
}