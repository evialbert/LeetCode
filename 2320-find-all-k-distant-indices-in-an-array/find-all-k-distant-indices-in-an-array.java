class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;
        int[] marker = new int[n + 1];

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int left = Math.max(0, i - k);
                int right = Math.min(n - 1, i + k);
                marker[left]++;
                if (right + 1 < n) marker[right + 1]--;
            }
        }

        List<Integer> result = new ArrayList<>();
        int runningSum = 0;
        for (int i = 0; i < n; i++) {
            runningSum += marker[i];
            if (runningSum > 0) {
                result.add(i);
            }
        }

        return result;
    }
}
