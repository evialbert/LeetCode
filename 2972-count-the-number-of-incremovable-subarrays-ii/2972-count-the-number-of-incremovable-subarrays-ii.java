class Solution {
    public long incremovableSubarrayCount(int[] nums) {
        int startPoint = nums.length;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= nums[i - 1]) {
                startPoint = i;
                break;
            }
        }

        if (startPoint == nums.length) {
            int n = nums.length;
            return (n * (n + 1)) / 2;
        }

        TreeMap<Integer, Integer> tm = new TreeMap<>();
        tm.put(nums[nums.length - 1], 1);
        int count = 2;

        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                break;
            }

            tm.put(nums[i], count);
            count++;
        }

        long sum = 0;

        for (int i = 1; i <= startPoint; i++) {
            if (tm.ceilingKey(nums[i - 1] + 1) == null) {
                sum++;
            } else {
                sum += (long)tm.get(tm.ceilingKey(nums[i - 1] + 1)) + 1;
            }
        }

        int firstCase = tm.get(tm.ceilingKey(0));
        sum += (long)firstCase + 1;

        return sum;
    }
}