class Solution {
    
    public int check(int num) { 
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        int swaps = 0;
        boolean[] vis = new boolean[n];
        int[][] pairs = new int[n][2];

        for (int i = 0; i < n; i++) {
            pairs[i][0] = nums[i];
            pairs[i][1] = i;
        }

        Arrays.sort(pairs, (a, b) -> {
            int first = check(a[0]);
            int second = check(b[0]);
            if (first != second) return first - second;
            return a[0] - b[0];
        });

        int[] newPos = new int[n];
        for (int i = 0; i < n; i++) {
            newPos[pairs[i][1]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] || newPos[i] == i) continue;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = newPos[j];
                if (j != i) swaps++;
            }
        }

        return swaps;
    }
}