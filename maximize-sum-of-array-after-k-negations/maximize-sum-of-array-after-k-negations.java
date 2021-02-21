class Solution {

    public int largestSumAfterKNegations(int[] A, int K) {

        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for (int a : A) queue.offer(a);

        while (K-- > 0) queue.offer(queue.poll() * -1); 

        int res = 0;

        while (!queue.isEmpty()) res += queue.poll(); 

        return res;

    }

}