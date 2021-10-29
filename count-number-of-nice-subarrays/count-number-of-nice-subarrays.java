class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int ret = 0, size = nums.length;
        int oddCountSum = 0;
        HashMap<Integer, Integer> record = new HashMap<>();
        record.put(0, 1);
        for (int num : nums) {
            if (num % 2 == 1) {
                oddCountSum++;
            }

            if (record.get(oddCountSum - k) != null) {
                ret += record.get(oddCountSum - k);
            }

            record.merge(oddCountSum, 1, Integer::sum);
        }

        return ret;
    }
}