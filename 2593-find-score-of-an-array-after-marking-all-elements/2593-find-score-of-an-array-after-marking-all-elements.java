class Solution {
    public long findScore(final int[] nums) {
        final int n = nums.length;
        final int[][] sorted = new int[n][2];

        for(int i = 0; i < n; ++i)
            sorted[i] = new int[] { nums[i], i };

        Arrays.sort(sorted, (a, b) -> a[0] - b[0]);

        final boolean[] indexes = new boolean[n];

        long sum = 0;

        for(final int[] s : sorted) {
            final int num = s[0], idx = s[1];

            if(!indexes[idx]) {
                if(idx + 1 < n)
                    indexes[idx + 1] = true;
                    
                if(idx - 1 > -1)
                    indexes[idx - 1] = true;

                indexes[idx] = true;

                sum += num;
            }
        }

        return sum;
    }
}