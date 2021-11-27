class Solution {
    public int maxEvents(int[][] events) {
        // edge, perf
        // greedy. for any day, pick the event that ends soon.
        // first, sort by start day.
        Arrays.sort(events, (a, b) -> a[0] - b[0]);        
        // then, we use pq - this will store end dates.
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ei = 0;
        int sd = events[ei][0];
        int ret = 0;
        while(pq.isEmpty() == false || ei < events.length) {
            // put end days of events that start on sd.
            while (ei < events.length && events[ei][0] == sd) {
                pq.offer(events[ei][1]);
                ei++;
            }
            
            // attend an event on day sd.
            if (!pq.isEmpty()) {
                pq.poll();
                ret++;
                // remove events that ends on day sd.
                // also if earliest ed is found, assign it to sd.
                while(!pq.isEmpty()) {
                    if (pq.peek() == sd)
                        pq.poll();
                    else
                        break;
                }
            }
            sd++;
        }
        return ret;
    }
}