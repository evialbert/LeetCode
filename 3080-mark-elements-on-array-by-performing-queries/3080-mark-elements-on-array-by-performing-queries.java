class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        int n = queries.length;
        long[] answer = new long[n];

        long total = 0;
        Set<Integer> markedIndices = new HashSet<>();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1, i2) -> {
            if (nums[i1] != nums[i2]) {
                return nums[i1] - nums[i2];
            }
            return i1 - i2;
        });
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            pq.add(i);
        }

        for (int i = 0; i < queries.length; i++) {
            if (pq.isEmpty()) {
                break;
            }
            
            int[] q = queries[i];
            int index = q[0];
            int k = q[1];

            if (markedIndices.add(index)) {
                total -= nums[index];
            }

            while (!pq.isEmpty() && k != 0) {
                index = pq.remove();
                if (markedIndices.add(index)) {
                    k--;
                    total -= nums[index];
                }
            }
            
            answer[i] = total;
        }

        return answer;
    }
}