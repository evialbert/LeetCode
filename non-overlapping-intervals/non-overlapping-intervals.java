     class Solution {
  public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[1]));
        int toRemove = 0;
        int maxTillNow = Integer.MIN_VALUE;
        for (int[] interval : intervals) {
            if (interval[0] < maxTillNow) {
                toRemove++;
            } else {
                maxTillNow = interval[1];
            }
        }
        return toRemove;
    }
     }