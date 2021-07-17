class Solution {
    
    private static class Interval {
        public int start;
        public int end;
        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    
    public int rectangleArea(int[][] rectangles) {
        int OPEN = 0, CLOSE = 1;
        int[][] events = new int[rectangles.length * 2][4];
        
        int t = 0;
        /**
        open of rectangle: add to active set
        close of rectangle: remove from active set
        */
        for (int[] rec: rectangles) {
            // y, open_or_close, start, end
            events[t++] = new int[]{ rec[1], OPEN, rec[0], rec[2] };
            events[t++] = new int[]{ rec[3], CLOSE, rec[0], rec[2] };
        }
        
        /**
        sort by current y index
        */
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));

        TreeMap<Interval, Integer> active = new TreeMap<>((a, b) -> {
            if (a.start != b.start) return a.start - b.start;
            return a.end - b.end;
        });
        // first y coordinate at the bottom
        int currentY = events[0][0];
        long ans = 0;
        for (int[] event : events) {
            int y = event[0], typ = event[1], x1 = event[2], x2 = event[3];

            // Calculate sum of intervals in active set, that's the active intervals in prev line
            if (y > currentY) {
                ans += calculateInterval(active) * (y - currentY);
                currentY = y;
            }

            /**
            add or remove new interval to current active
            */
            if (typ == OPEN) {
                addInterval(active, x1, x2);
            } else {
                removeInterval(active, x1, x2);
            }
        }
        ans %= 1_000_000_007;
        return (int) ans;
    }
    
    /**
    using tree map, should be able to insert in logn time
    */
    private void addInterval(TreeMap<Interval, Integer> map, int x1, int x2) {
        Interval interval = new Interval(x1, x2);
        map.put(interval, map.getOrDefault(interval, 0) + 1);
    }
    
    /**
    using tree map, should be able to remove in logn time
    */
    private void removeInterval(TreeMap<Interval, Integer> map, int x1, int x2) {
        Interval interval = new Interval(x1, x2);
        map.put(interval, map.getOrDefault(interval, 0) - 1);
        if (map.get(interval) == 0) map.remove(interval);
    }
    
    private long calculateInterval(TreeMap<Interval, Integer> map) {
        long query = 0;
        int cur = -1;
        for (Interval interval : map.keySet()) {
            cur = Math.max(cur, interval.start);
            query += Math.max(interval.end - cur, 0);
            cur = Math.max(cur, interval.end);
        }
        return query;
    }
    
}