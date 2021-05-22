class Solution {
    public boolean isPossible(int[] nums) {
        // key: end number, value: queue of length
        Map<Integer, PriorityQueue<Integer>> m = new HashMap<>();    
        for (int n : nums) {
            int prev = n - 1;
            int len = 0;
            if (m.containsKey(prev) && m.get(prev).size() > 0) {
                PriorityQueue<Integer> q = m.get(prev);
                len = q.poll();
            }
            len++;
            if (!m.containsKey(n)) {
                m.put(n, new PriorityQueue<Integer>());
            }
            
            PriorityQueue<Integer> q = m.get(n);
            q.offer(len);
        }
        
        for (PriorityQueue<Integer> q : m.values()) {
            if (q.size() > 0 && q.peek() < 3) return false;
        }
        return true;
    }
}