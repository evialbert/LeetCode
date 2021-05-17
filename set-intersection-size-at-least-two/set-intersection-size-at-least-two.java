class Solution {
   public int intersectionSizeTwo(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]); // Sort intervals: 1- end 2- start- O(nlogn)
        List<Integer> res = new ArrayList<>();
        res.add(intervals[0][1] - 1); // Add one before end
        res.add(intervals[0][1]); // Add end
        for (int i = 1; i < n; i++) { // O(n)
            int start = intervals[i][0];
            int end = intervals[i][1];
            int size = res.size();
            int last = res.get(size - 1);
            int secondLast = res.get(size - 2);
            if (start > last) { // We need to add two fresh points
                res.add(end - 1);
                res.add(end);
            } else if (start == last) res.add(end); // We already added one. We need to add the end of this interval
            else if (start > secondLast) res.add(end); // We already added last. We need one more
        }
        return res.size();
    }
}