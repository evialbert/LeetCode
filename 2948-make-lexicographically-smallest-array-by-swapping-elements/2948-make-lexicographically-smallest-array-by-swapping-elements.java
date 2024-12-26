class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int[] copy = nums.clone();
        Arrays.sort(copy);
        // if interval is within limit, then we can swap them without constraint
        Map<Integer, Queue<Integer>> map = new HashMap<>();
        Map<Integer, Integer> ht = new HashMap<>();
        int index = 0;
        map.put(index, new LinkedList<>());
        map.get(index).add(copy[0]);
        ht.put(copy[0], index);
        for (int i = 1; i < copy.length; i++) {
            if (copy[i] - copy[i - 1] <= limit) {
                map.get(index).add(copy[i]);
                ht.put(copy[i], index);
            } else {
                index++;
                map.put(index, new LinkedList<>());
                map.get(index).add(copy[i]);
                ht.put(copy[i], index);
            }
        }
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            index = ht.get(nums[i]);
            Queue<Integer> q = map.get(index);
            res[i] = q.poll();
        }
        return  res;
    }
}