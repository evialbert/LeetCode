class Solution {

    int[] arr;
    int[] st;
    int[] end;
    int time;
    boolean[] vis;

    public int maximumInvitations(int[] favorite) {
        arr = favorite;
        st = new int[favorite.length];
        end = new int[favorite.length];
        Arrays.fill(st, -1);
        Arrays.fill(end, -1);
        vis = new boolean[favorite.length];
        int ans = 0;
        for (int i = 0; i < favorite.length; ++i) {
            if (st[i] == -1) {
                ans = Math.max(ans, cycleLength(i));
            }
        }

        List<Integer>[] revPos = new ArrayList[favorite.length];
        for (int i = 0; i < favorite.length; ++i) {
            revPos[i] = new ArrayList<>();
        }
        for (int i = 0; i < favorite.length; ++i) {
            revPos[favorite[i]].add(i);
        }
        int ans2 = 0;
        for (int i = 0; i < favorite.length; i++) {
            if (!vis[i] && favorite[favorite[i]] == i) {
                vis[i] = true;
                vis[favorite[i]] = true;
                int t1 = dfs(i, revPos);
                int t2 = dfs(favorite[i], revPos);
                ans2 += t1 + t2;
            }
        }

        return Math.max(ans, ans2);
    }

    public int dfs(int node, List<Integer>[] revPos) {
        vis[node] = true;
        int ans = 0;
        for (int i : revPos[node]) {
            if (!vis[i])
                ans = Math.max(ans, dfs(i, revPos));
        }
        return ans + 1;
    }

    public int cycleLength(int node) {
        st[node] = ++time;
        int newNode = arr[node];
        int val = 0;
        if (st[newNode] == -1) {
            val = cycleLength(newNode);
        } else if (end[newNode] == -1) {
            val = time - st[newNode] + 1;
        }
        end[node] = time;
        return val;
    }
}