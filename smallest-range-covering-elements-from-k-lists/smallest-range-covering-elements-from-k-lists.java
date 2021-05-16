class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int max = Integer.MIN_VALUE;
        int l = 0;
        int r = Integer.MAX_VALUE;
        for (int i = 0; i < nums.size(); ++i) {
            pq.offer(new int[]{nums.get(i).get(0), i, 0});
            max = Math.max(max, nums.get(i).get(0));
        }
        while(pq.size() == nums.size()) {
            int[] p = pq.poll();
            if (max - p[0] < r - l) {
                l = p[0];
                r = max;
            }
            if (p[2] + 1 < nums.get(p[1]).size()) {
                max = Math.max(max, nums.get(p[1]).get(p[2] + 1));
                pq.offer(new int[]{nums.get(p[1]).get(p[2] + 1), p[1], p[2] + 1});
            }
        }
        return new int[]{l, r};
    }
}