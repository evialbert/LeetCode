class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int[][] workers = new int[quality.length][];
        for(int i = 0; i < workers.length ; i++) {
            workers[i] = new int[] {quality[i], wage[i]};
        }
        Arrays.sort(workers, Comparator.comparing(w -> (double)w[1] / w[0]));

        PriorityQueue<Integer> qualityQueue = new PriorityQueue<>(K, Comparator.reverseOrder());
        double result = Double.MAX_VALUE;
        int totalQuality = 0;
        for(int i = 0 ; i < workers.length ; i++) {
            qualityQueue.add(workers[i][0]);
            totalQuality += workers[i][0];
            if (qualityQueue.size() > K) {
                totalQuality -= qualityQueue.poll();
            }
            if (qualityQueue.size() == K) {
                double wageRatio = (double)workers[i][1] / (double)workers[i][0];
                result = Math.min(result, totalQuality * wageRatio);
            }
        }
        return result;
    }
}