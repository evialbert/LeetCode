class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        int[] segmentTree = new int[4 * n];

        // Build segment tree
        build(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int fruit : fruits) {
            if (!querySegmentTree(0, 0, n - 1, segmentTree, fruit)) {
                unplaced++;
            }
        }

        return unplaced;
    }

    private void build(int i, int l, int r, int[] baskets, int[] segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int m = (l + r) / 2;

        build(2 * i + 1, l, m, baskets, segmentTree);
        build(2 * i + 2, m + 1, r, baskets, segmentTree);

        segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    private boolean querySegmentTree(int i, int l, int r, int[] segmentTree, int val) {
        if (segmentTree[i] < val) {
            return false; // No basket in this segment
        }

        if (l == r) {
            segmentTree[i] = -1; // Mark basket as used
            return true;
        }

        int mid = (l + r) / 2;
        boolean placed;

        if (segmentTree[2 * i + 1] >= val) {
            placed = querySegmentTree(2 * i + 1, l, mid, segmentTree, val);
        } else {
            placed = querySegmentTree(2 * i + 2, mid + 1, r, segmentTree, val);
        }

        segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return placed;
    }
}