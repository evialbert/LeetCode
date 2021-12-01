class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] map = new int[n];
        for (int i = 0; i < n; i++)
            map[i] = i;
        int count = n;
        for (int i = 0; i < n; i++) {
            int root = find(map, i);
            if (leftChild[i] != -1) {
                int rootL = find(map, leftChild[i]);
                if (rootL == root || (root == i && rootL != leftChild[i]))
                    return false;
                map[rootL] = root;
                count--;
            }
            if (rightChild[i] != -1) {
                int rootR = find(map, rightChild[i]);
                if (rootR == root || (root == i && rootR != rightChild[i]))
                    return false;
                map[rootR] = root;
                count--;
            }
        }
        return count == 1;
    }
    public int find(int[] map, int i) {
        if (map[i] != i)
            map[i] = find(map, map[i]);
        return map[i];
    }
}