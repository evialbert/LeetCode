class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length, ans = 0;

        for (int i = 0; i <= 30; i++) {
            int mask = 1 << i, size = 0;
            int[] arr = new int[n];

            for (int j : nums) {
                if ((j & mask) == 0)
                    continue;

                int left = 0, right = size;
                while (left < right) {
                    int mid = (left + right) >>> 1;
                    if (arr[mid] < j)
                        left = mid + 1;
                    else
                        right = mid;
                }

                arr[left] = j;
                if (left == size)
                    size++;
            }

            ans = Math.max(ans, size);
        }

        return ans;
    }
}