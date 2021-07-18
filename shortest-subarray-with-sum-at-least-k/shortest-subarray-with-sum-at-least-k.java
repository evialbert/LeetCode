class Solution {
    public int shortestSubarray(int[] A, int K) {
        int n = A.length;
        long[] sums = new long[n + 1];
        
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + A[i - 1];
        }
        
        int answer = n + 1;
        Deque<Integer> deque = new LinkedList<>();
        for (int index = 0; index <= n; index++) {
            long sum = sums[index];
            
            while (!deque.isEmpty() && sums[deque.getLast()] >= sum) {
                deque.removeLast();
            }
            
            while (!deque.isEmpty() && sums[deque.getFirst()] + K <= sum) {
                answer = Math.min(answer, index - deque.removeFirst());
            }
            
            deque.addLast(index);
        }
        
        return answer == n + 1 ? -1 : answer;
    }
}