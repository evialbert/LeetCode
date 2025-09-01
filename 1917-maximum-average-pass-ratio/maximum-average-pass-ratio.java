class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            double ga = gain(a[0], a[1]);
            double gb = gain(b[0], b[1]);
            return Double.compare(gb, ga); // max-heap by gain
        });

        for (int[] c : classes) {
            pq.offer(new int[]{c[0], c[1]});
        }

        while (extraStudents-- > 0) {
            int[] c = pq.poll();
            c[0]++; // one more pass
            c[1]++; // one more total
            pq.offer(c);
        }

        double sum = 0.0;
        for (int[] c : pq) {
            sum += (double) c[0] / c[1];
        }
        return sum / classes.length;
    }

    private double gain(int p, int t) {
        return ((double) (t - p)) / (t * (t + 1.0)); 
    }
}