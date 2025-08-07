class Solution {
    public int maxCollectedFruits(int[][] fruits) {
        int n = fruits.length;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += fruits[i][i];
        }

        int[] rightPath = new int[3];
        rightPath[0] = fruits[0][n - 1];

        int[] bottomPath = new int[3];
        bottomPath[0] = fruits[n - 1][0];

        int window = 2;

        for (int step = 1; step < n - 1; step++) {
            int[] newRight = new int[window + 2];
            int[] newBottom = new int[window + 2];

            for (int dist = 0; dist < window; dist++) {
                int left = (dist - 1 >= 0) ? rightPath[dist - 1] : 0;
                int mid = rightPath[dist];
                int right = (dist + 1 < rightPath.length) ? rightPath[dist + 1] : 0;
                newRight[dist] = Math.max(left, Math.max(mid, right)) + fruits[step][n - 1 - dist];

                left = (dist - 1 >= 0) ? bottomPath[dist - 1] : 0;
                mid = bottomPath[dist];
                right = (dist + 1 < bottomPath.length) ? bottomPath[dist + 1] : 0;
                newBottom[dist] = Math.max(left, Math.max(mid, right)) + fruits[n - 1 - dist][step];
            }

            rightPath = newRight;
            bottomPath = newBottom;

            if (window - n + 4 + step <= 1) {
                window += 1;
            } else if (window - n + 3 + step > 1) {
                window -= 1;
            }
        }

        return total + rightPath[0] + bottomPath[0];
    }
}