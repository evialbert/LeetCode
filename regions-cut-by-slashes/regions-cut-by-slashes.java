class Solution {
    public class UnionFind {
        public int[] parent;
        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        public void union(int a, int b) {
            parent[find(a)] = find(b);
        }
        public int find(int a) {
            if (a != parent[a]) {
                parent[a] = find(parent[a]);
            }
            return parent[a];
        }
    }
    public int regionsBySlashes(String[] grid) {
        //strategy: Union Find
        //0 = north, 1 = east, 2 = south, 3 = west
        int n = grid.length;
        //each cell has 4 nodes
        UnionFind uf = new UnionFind(4 * n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //find curr root and val
                int root = 4 * (i * n + j);
                char val = grid[i].charAt(j);
                //slashes union
                //connect north-west and south-east
                if (val != '\\') {
                    uf.union(root, root + 3);
                    uf.union(root + 1, root + 2);
                }
                //slashes union
                //connects north-east and south-west
                if (val != '/') {
                    uf.union(root, root + 1);
                    uf.union(root + 2, root + 3);
                }
                //north-south union
                if (i - 1 >= 0) {
                    uf.union(root, root - 4 * n + 2);
                }
                //east-west union
                if (j - 1 >= 0) {
                    uf.union(root + 3, root - 4 + 1);
                }
            }
        }
        //see how many nodes are still within its own node
        int answer = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            answer += (uf.find(i) == i) ? 1 : 0;
        }
        return answer;
    }
}