class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        PriorityQueue<String> pq = new PriorityQueue<>((a, b) -> {
            if (a.length() == b.length()) {
                return a.compareTo(b);
            }
            return a.length() - b.length();
        }); // min heap

        for (String x : nums) {
            pq.offer(x);
            while (pq.size() > k) {
                pq.poll();
            }
        }
        return pq.poll();
    }
}