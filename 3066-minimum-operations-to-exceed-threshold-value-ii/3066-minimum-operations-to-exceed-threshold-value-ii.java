class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Double> pq = new PriorityQueue<>();
        for(int curr:nums) {
            pq.add((double)curr);
        }
        
        int count = 0;
        
        while(!pq.isEmpty() && pq.size() >= 2 && pq.peek() < k) {
            double x = pq.remove();
            double y = pq.remove();
            
            double val = Math.min(x,y) * 2 + Math.max(x,y);
            pq.add(val);
            count++;
        }
        
        return count;
    }
}