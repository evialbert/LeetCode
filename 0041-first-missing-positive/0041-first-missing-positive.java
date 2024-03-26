class Solution {
    public int firstMissingPositive(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i : nums) {
            if (i > 0) {
                hm.put(i, hm.getOrDefault(i, 0) + 1);
            }
        }
        int min = 1;
        while (hm.containsKey(min)) {
            min++;
        }
        System.gc();
        return min;
    }
}