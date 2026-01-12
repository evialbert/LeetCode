class Solution {
    public int minimumDistance(int[] nums) {
        int minSoFar = Integer.MAX_VALUE;
        HashMap<Integer, List<Integer>> mMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            List<Integer> p = mMap.getOrDefault(nums[i], new ArrayList<>());
            p.add(i);
            mMap.put(nums[i], p);

            if (p.size() >= 3) {
                minSoFar = Math.min(minSoFar, p.get(p.size() - 1) - p.get(0));
                p.remove(0);
            }
        }

        return minSoFar == Integer.MAX_VALUE ? -1 : minSoFar * 2;
    }
}